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

#ifndef NUNIFORM_H
#define NUNIFORM_H

#include <QObject>
#include <QString>

#include "nstatus.h"
#include "nresponse.h"

class NRequest;

/*!
 * \class NUniform
 * \brief Uniform interface common to all resource types
 */

class NUniform : public QObject {
protected:
    /*!
     * Override this method in a derived class to handle a GET request.
     * By default this methods returns NStatus::CLIENT_ERROR_METHOD_NOT_ALLOWED
     * \param request const reference to a Request object
     * \param response a reference to the Response object built by the Connector
     * \return the resource is responsible for compiling a Response object which
     *    will be sent to the client
     */
    virtual void handleGet(const NRequest& request, NResponse& response)
    { Q_UNUSED(request) response.setStatus(NStatus::CLIENT_ERROR_METHOD_NOT_ALLOWED); }

    /*!
     * Override this method in a derived class to handle a HEAD request.
     * By default this methods returns NStatus::CLIENT_ERROR_METHOD_NOT_ALLOWED
     * \note this method is much like GET but must NOT return a response body
     *    (a Representation)
     * \param request const reference to a Request object
     * \param response a reference to the Response object built by the Connector
     * \return the resource is responsible for compiling a Response object which
     *    will be sent to the client
     */
    virtual void handleHead(const NRequest& request, NResponse& response)
    { Q_UNUSED(request) response.setStatus(NStatus::CLIENT_ERROR_METHOD_NOT_ALLOWED); }

    /*!
     * Override this method in a derived class to handle a PUT request.
     * By default this methods returns NStatus::CLIENT_ERROR_METHOD_NOT_ALLOWED
     * \param request const reference to a Request object
     * \param response a reference to the Response object built by the Connector
     * \return the resource is responsible for compiling a Response object which
     *    will be sent to the client
     */
    virtual void handlePut(const NRequest& request, NResponse& response)
    { Q_UNUSED(request) response.setStatus(NStatus::CLIENT_ERROR_METHOD_NOT_ALLOWED); }

    /*!
     * Override this method in a derived class to handle a POST request.
     * By default this methods returns NStatus::CLIENT_ERROR_METHOD_NOT_ALLOWED
     * \param request const reference to a Request object
     * \param response a reference to the Response object built by the Connector
     * \return the resource is responsible for compiling a Response object which
     *    will be sent to the client
     */
    virtual void handlePost(const NRequest& request, NResponse& response)
    { Q_UNUSED(request) response.setStatus(NStatus::CLIENT_ERROR_METHOD_NOT_ALLOWED); }

    /*!
     * Override this method in a derived class to handle a OPTIONS request.
     * By default this methods returns NStatus::CLIENT_ERROR_METHOD_NOT_ALLOWED
     * \param request const reference to a Request object
     * \param response a reference to the Response object built by the Connector
     * \return the resource is responsible for compiling a Response object which
     *    will be sent to the client
     */
    virtual void handleOptions(const NRequest& request, NResponse& response) const
    { Q_UNUSED(request) response.setStatus(NStatus::CLIENT_ERROR_METHOD_NOT_ALLOWED); }

    /*!
     * Override this method in a derived class to handle a DELETE request.
     * By default this methods returns NStatus::CLIENT_ERROR_METHOD_NOT_ALLOWED
     * \param request const reference to a Request object
     * \param response a reference to the Response object built by the Connector
     * \return the resource is responsible for compiling a Response object which
     *    will be sent to the client
     */
    virtual void handleDelete(const NRequest& request, NResponse& response)
    { Q_UNUSED(request) response.setStatus(NStatus::CLIENT_ERROR_METHOD_NOT_ALLOWED); }

private:
    bool m_started;
    QString m_resourceUri;
};


#endif /* NUNIFORM_H */
