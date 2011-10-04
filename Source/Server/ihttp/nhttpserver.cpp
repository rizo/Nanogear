/*
 * Nanogear - C++ web development framework
 *
 * This library is based on Restlet (R) <http://www.restlet.org> by Noelios Technologies
 * Copyright (C) 2005-2008 by Noelios Technologies <http://www.noelios.com>
 * Restlet is a registered trademark of Noelios Technologies. All other marks and
 * trademarks are property of their respective owners.
 *
 * Copyright (C) 2008-2009 Lorenzo Villani.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "nhttpserver.h"

#include <QUrl>
#include <QTcpSocket>
#include <QTcpServer>
#include <QHttpRequestHeader>

#include <nmethod.h>
#include <nrequest.h>
#include <nresponse.h>
#include <nresource.h>
#include <napplication.h>
#include <nrepresentation.h>

#include "nutility.h"

void NHTTPServer::start()
{
    qDebug() << Q_FUNC_INFO << "Starting HTTP server on " << address() << ":" << port();
    listen(address(), port());
    connect(this, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

void NHTTPServer::onNewConnection()
{
    m_clientSocket = nextPendingConnection();
    connect(m_clientSocket, SIGNAL(readyRead()), SLOT(onClientReadyRead()));
    connect(m_clientSocket, SIGNAL(disconnected()), m_clientSocket, SLOT(deleteLater()));
}

void NHTTPServer::onClientReadyRead()
{
    qDebug() << Q_FUNC_INFO << "Handling request (size:" << m_clientSocket->size() << ")";

    /* ***************************************************************
     * This part of the method is dedicated to fill the Request object
     * ***************************************************************/
    // Separate the HTTP headers from the request body (if any)
    QByteArray rawRequestHeader;

    for (;;) {
        QByteArray line(m_clientSocket->readLine());

        if (line == "\r\n")
            break;

        rawRequestHeader += line;
    }

    QHttpRequestHeader requestHeader(rawRequestHeader);

    qDebug() << Q_FUNC_INFO << "Requested path: " << requestHeader.path();

    // Fill Method by using informations supplied by the client
    NMethod requestedMethod = NMethod::valueOf(requestHeader.method().toUpper());

    //
    // Get the entity
    //
    QByteArray entityBody;

    if (requestHeader.hasKey("Content-Length"))
        entityBody = m_clientSocket->read(requestHeader.value("Content-Length").toLongLong());
    else if (requestedMethod.hasBody())
        entityBody = m_clientSocket->readAll();

    NRepresentation entity(entityBody, requestHeader.value("Content-Type"));

    NPreferenceList<NMimeType> acceptedMimeTypes(
        getPreferenceListFromHeader<NMimeType>(requestHeader.value("Accept")));

    NPreferenceList<QLocale> acceptedLocales(
        getPreferenceListFromHeader<QLocale>(requestHeader.value("Accept-Language")));

    NPreferenceList<QTextCodec*> acceptedCharsets(
        getPreferenceListFromHeader<QTextCodec*>(requestHeader.value("Accept-Charset")));


    // Fill the ClientInfo object
    NClientInfo clientInfo(acceptedMimeTypes, acceptedLocales, acceptedCharsets,
                           requestHeader.value("User-Agent"));


    /* ***************************************************************
     * Query strings
     * ***************************************************************/
    QHash<QString, QString> parameters;

    // Overcome the limitations of the Q_FOREACH macro
    typedef QPair<QByteArray, QByteArray> KeyValuePair;

    QUrl queryString(requestHeader.path());

    foreach(const KeyValuePair& keyValue, queryString.encodedQueryItems()) {
        parameters[keyValue.first] = keyValue.second;
    }

    // Handle POST query string
    if (entity.hasFormat("application/x-www-form-urlencoded")) {
        //             ↓ workaround to get QUrl recognize a query string
        QUrl formData("?" + entity.data("application/x-www-form-urlencoded"));
        foreach(const KeyValuePair& keyValue, formData.encodedQueryItems()) {
            parameters[keyValue.first] = keyValue.second;
        }
    }

    // Fill Request object
    NRequest request(requestHeader.method(), clientInfo, &entity);

    request.setResourceRef(queryString.path());

    request.setParameters(parameters);


    /* ***************************************************************
     * Handle the request
     * ***************************************************************/
    // Let the Application's root() handle routing (if a Router class) or let
    // it respond at every uri, if needed
    qDebug() << Q_FUNC_INFO << "Handling the request";

    NResponse response;

    NResource* resource = NApplication::instance()->createRoot();

    resource->handleRequest(request, response);



    /* *******************************************************************
     * Extract data from the Response object and answer back to the client
     * *******************************************************************/
    // Retrieve the representation from the response
    //! \note This should be wrapped in a QPointer<T>
    const NRepresentation* representation = response.representation();

    /// \note Unused
    //QTextCodec* codec = clientInfo.acceptedTextCodecs().top();

    QHttpResponseHeader responseHeader(response.status().code(), response.status().name(),
                                       requestHeader.majorVersion(), requestHeader.minorVersion());

    responseHeader.setValue("Connection", requestHeader.value("Connection"));

    if (responseHeader.value("Connection").isEmpty()) {
        if (responseHeader.majorVersion() <= 1 && responseHeader.minorVersion() == 0)
            responseHeader.setValue("Connection", "close");
    }

    responseHeader.setValue("Server", "Nanogear");

    if (response.expirationDate().isValid()) {
        responseHeader.setValue("Expires", response.expirationDate().toUTC()
                                .toString("dd MMM yyyy ss:mm:hh") + " GMT");
    }

    // If the resource provides only one representation send it anyway
    QByteArray responseData;

    if (representation != 0) { // the resource may or may not return a representation
        if (representation->formats().count() == 1) {
            responseHeader.setContentType(representation->formats().at(0));
            responseData = representation->data(representation->formats().at(0));
        } else {
            responseHeader.setContentType(representation->format(clientInfo.acceptedMimeTypes())
                                          .toString());
            responseData = representation->data(clientInfo.acceptedMimeTypes());
        }
    }

    responseHeader.setValue("Content-Length", QString::number(responseData.length()));

    // And finally send data back to the client
    qDebug() << Q_FUNC_INFO << "sending data back to the client (size:"
    << responseHeader.value("Content-Length") << ") -" << responseHeader.value("Content-Type");

    m_clientSocket->write(responseHeader.toString().toUtf8());
    m_clientSocket->write(responseData);
    m_clientSocket->disconnectFromHost();

    delete resource; // Clean-up
}
