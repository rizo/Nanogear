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

#ifndef NREQUEST_H
#define NREQUEST_H

#include <QObject>
#include <QHash>
#include <QString>
#include <QByteArray>

#include "nmethod.h"
#include "nclientinfo.h"

class NRepresentation;

/*!
 * \class NRequest
 * \brief This class encapsulates and abstracts a client request
 *
 * A Request object represents a client request. That is, every client, either
 * a web browser or another program, will usually include supported media types,
 * supported charset, the resource context, request method and request
 * parameters.
 *
 * It is connector's (or, in general, a Server implementation) responsiblity
 * to fill this object and pass a const reference to resources methods handlers.
 *
 * Informations sent by the client (such as supported media types, character
 * encodings, etc) is encapsulated in a NClientInfo object and is read-only.
 *
 * The requested context is encapsulated by a Context object and is read-only.
 *
 * The request body is represented by a read-only QByteArray
 */

class NRequest : public QObject
{
public:
    /*!
     * A constructor used to initialize values.
     * This constructor is intended to be used only by 'Server' implementations
     *
     * \param method A const reference to a NMethod object
     * \param clientInfo A const reference to a NClientInfo
     * \param body A pointer to the body representation
     */
    NRequest(const NMethod& method, const NClientInfo& clientInfo, NRepresentation* body) :
            m_method(method), m_clientInfo(clientInfo), m_representation(body) {}


    /*!
     * When a client makes a request it usually specifies a method. It used to
     * determine which handler should be called on a resource.
     * \return An object encapsulating a method
     */
    const NMethod& method() const
    { return m_method; }

    /*!
     * \param method The request method
     */
    void setNMethod(const NMethod& method)
    { m_method = method; }

    /*!
     * A client usually attaches additional informations to the request, this
     * method can be used to retrieve it.
     * \return An object representing additional informations supplied by the client
     */
    const NClientInfo& clientInfo() const
    { return m_clientInfo; }

    /*!
     * Set the client informations attached to this request
     * \param clientInfo The informations supplied by the client
     */
    void setClientInfo(const NClientInfo& clientInfo)
    { m_clientInfo = clientInfo; }

    /*!
     * \return The representation attached to this request
     */
    const NRepresentation* entity() const
    { return m_representation; }

    /*!
     * Set the representation attached to this Request
     * \param representation A pointer to a Representation object
     */
    void setEntity(NRepresentation* representation)
    { m_representation = representation; }

    /*!
     * \return The path requested by the client
     */
    const QString& resourceRef() const
    { return m_resourceRef; }

    /*!
     * Set the path requested by the client
     * \param path A string representing the requested path
     */
    void setResourceRef(const QString& path)
    { m_resourceRef = path; }

    /*!
     * \param parameters Set the request parameter
     */
    void setParameters(const QHash<QString, QString>& parameters)
    { m_parameters = parameters; }

    /*!
     * \return The request parameters
     */
    const QHash<QString, QString>& parameters() const
    { return m_parameters; }

private:
    NMethod m_method;
    NClientInfo m_clientInfo;
    QString m_resourceRef;
    QHash<QString, QString> m_parameters;
    NRepresentation* m_representation;
};

#endif /* NREQUEST_H */
