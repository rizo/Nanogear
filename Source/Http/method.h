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

#ifndef NMETHOD_H
#define NMETHOD_H

#include <QString>

#include "nmetadata.h"

/*!
 * \class NMethod
 * \brief Encapsulates the requested method
 *
 * Used to determine which method to execute to handle a request. It is usually
 * filled by a concrete implementation of Server.
 */
class NMethod : public NMetadata {
public:

    NMethod(const QString& name) : NMetadata(name) {}

    NMethod(const QString& name, const QString& description) : NMetadata(name, description) {}

    bool operator==(const NMethod& type) const;

    /*!
     * Retrieve an instance of a NMethod class from the method's name
     *
     * \param methodName Requested method name
     * \return An instance of the default methods provided, otherwise a new NMethod instance with
     *      methodName as name (normalized to upper case)
     */
    static NMethod valueOf(const QString& methodName);

    /*!
     * \return true if this method has a body
     */
    bool hasBody() const;

    /*!
     * Used with a proxy that can dynamically switch to being a tunnel.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec9.html#sec9.9">HTTP RFC - 9.9 CONNECT</a>
     */
    static const NMethod CONNECT;

    /*!
     * Creates a duplicate of the source resource, identified by the
     * Request-URI, in the destination resource, identified by the URI in the
     * Destination header.
     *
     * \see <a href="http://www.webdav.org/specs/rfc2518.html#METHOD_COPY">WEBDAV RFC - 8.8 COPY Method</a>
     */
    static const NMethod COPY;

    /*!
     * Requests that the origin server deletes the resource identified by the
     * request URI.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec9.html#sec9.7">HTTP RFC - 9.7 DELETE</a>
     */
    static const NMethod DELETE;

    /*!
     * Retrieves whatever information (in the form of an entity) that is
     * identified by the request URI.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec9.html#sec9.3">HTTP RFC - 9.3 GET</a>
     */
    static const NMethod GET;

    /*!
     * Identical to GET except that the server must not return a message body in
     * the response but only the message header.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec9.html#sec9.4">HTTP RFC - 9.4 GET</a>
     */
    static const NMethod HEAD;

    /*!
     * Used to take out a lock of any access type on the resource identified by
     * the request URI.
     *
     * \see <a href="http://www.webdav.org/specs/rfc2518.html#METHOD_LOCK">WEBDAV RFC - 8.10 LOCK Method</a>
     */
    static const NMethod LOCK;

    /*!
     * MKCOL creates a new collection resource at the location specified by the
     * Request URI.
     *
     * \see <a href="http://www.webdav.org/specs/rfc2518.html#METHOD_MKCOL">WEBDAV RFC - 8.3 MKCOL Method</a>
     */
    static const NMethod MKCOL;

    /*!
     * Logical equivalent of a copy, followed by consistency maintenance
     * processing, followed by a delete of the source where all three actions
     * are performed atomically.
     *
     * \see <a href="http://www.webdav.org/specs/rfc2518.html#METHOD_MOVE">WEBDAV RFC - 8.3 MKCOL Method</a>
     */
    static const NMethod MOVE;

    /*!
     * Requests for information about the communication options available on the
     * request/response chain identified by the URI.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec9.html#sec9.2">HTTP RFC - 9.2 OPTIONS</a>
     */
    static const NMethod OPTIONS;

    /*!
     * Requests that the origin server accepts the entity enclosed in the
     * request as a new subordinate of the resource identified by the request
     * URI.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec9.html#sec9.5">HTTP RFC - 9.5 POST</a>
     */
    static const NMethod POST;

    /*!
     * Retrieves properties defined on the resource identified by the request
     * URI.
     *
     * \see <a href="http://www.webdav.org/specs/rfc2518.html#METHOD_PROPFIND">WEBDAV RFC - 8.1 PROPFIND</a>
     */
    static const NMethod PROPFIND;

    /*!
     * Processes instructions specified in the request body to set and/or remove
     * properties defined on the resource identified by the request URI.
     *
     * \see <a href="http://www.webdav.org/specs/rfc2518.html#METHOD_PROPPATCH">WEBDAV RFC - 8.2 PROPPATCH</a>
     */
    static const NMethod PROPPATCH;

    /*!
     * Requests that the enclosed entity be stored under the supplied request
     * URI.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec9.html#sec9.6"HTTP RFC - 9.6 PUT</a>
     */
    static const NMethod PUT;

    /*!
     * Used to invoke a remote, application-layer loop-back of the request
     * message.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec9.html#sec9.8">HTTP RFC - 9.8 TRACE</a>
     */
    static const NMethod TRACE;

    /*!
     * Removes the lock identified by the lock token from the request URI, and
     * all other resources included in the lock.
     *
     * \see <a href="http://www.webdav.org/specs/rfc2518.html#METHOD_UNLOCK">WEBDAV RFC - 8.11 UNLOCK Method</a>
     */
    static const NMethod UNLOCK;
};

#endif /* NMETHOD_H */
