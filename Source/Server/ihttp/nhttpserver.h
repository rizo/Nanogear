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

#ifndef CONNECTORS_IHTTP_NHTTPSERVER_H
#define CONNECTORS_IHTTP_NHTTPSERVER_H 1

#include <QTcpServer>

#include <nserver.h>

class QTcpSocket;

/*!
 * \class NHTTPServer
 * \brief A simple HTTP 1.1 server
 * \ingroup HTTP Server
 *
 * This is a concrete Server implementation providing a very simple HTTP 1.1
 * server.
 *
 * \note It is not meant to be production-ready.
 */
class NHTTPServer : public QTcpServer, public NServer
{
    Q_OBJECT
public:
    /*!
     * \param port A port to listen on (default: 8080)
     * \param listenAddress The address to listen on (default: QHostAddress::Any)
     */
    NHTTPServer(int port = 8080, const QHostAddress& listenAddress = QHostAddress::Any) :
            NServer(port, listenAddress) {}

public:
    /*!
     * Make the server listen for incoming connections
     */
    void start();

public slots:
    /*!
     * This slot is called when a client connects to this QTcpServer, it just
     * get a pointer to the pending connection and connects a couple of signals,
     * the control then passes to onClientReadyRead()
     */
    void onNewConnection();

    /*!
     * Handle the request
     */
    void onClientReadyRead();

private:
    QTcpSocket* m_clientSocket;
};

#endif /* CONNECTORS_IHTTP_NHTTPSERVER_H */
