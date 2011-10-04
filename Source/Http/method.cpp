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


#include "nmethod.h"

// Inizialize constants
const NMethod NMethod::CONNECT("CONNECT", "Used with a proxy that can dynamically switch to being "
        "a tunnel");

const NMethod NMethod::COPY("COPY", "Creates a duplicate of the source resource, identified by the "
        "Request-URI, in the destination resource, identified by the URI in the Destination header");

const NMethod NMethod::DELETE("DELETE", "Requests that the origin server deletes the resource "
        "identified by the request URI");

const NMethod NMethod::GET("GET", "Retrieves whatever information (in the form of an entity) "
        "that is identified by the request URI");

const NMethod NMethod::HEAD("HEAD", "Identical to GET except that the server must not return a "
        "message body in the response");

const NMethod NMethod::LOCK("LOCK", "Used to take out a lock of any access type (WebDAV)");

const NMethod NMethod::MKCOL("MKCOL", "Used to create a new collection (WebDAV)");

const NMethod NMethod::MOVE("MOVE", "Logical equivalent of a copy, followed by consistency "
        "maintenance processing, followed by a delete of the source (WebDAV)");

const NMethod NMethod::OPTIONS("OPTIONS", "Requests for information about the communication "
        "options available on the request/response chain identified by the URI");

const NMethod NMethod::POST("POST", "Requests that the origin server accepts the entity enclosed "
        "in the request as a new subordinate of the resource identified by the request URI");

const NMethod NMethod::PROPFIND("PROPFIND", "Retrieves properties defined on the resource "
        "identified by the request URI");

const NMethod NMethod::PROPPATCH("PROPPATCH", "Processes instructions specified in the request "
        "body to set and/or remove properties defined on the resource identified by the "
        "request URI");

const NMethod NMethod::PUT("PUT", "Requests that the enclosed entity be stored under the supplied "
        "request URI");

const NMethod NMethod::TRACE("TRACE", "Used to invoke a remote, application-layer loop-back of "
        "the request message");

const NMethod NMethod::UNLOCK("UNLOCK", "Removes the lock identified by the lock token from the "
        "request URI, and all other resources included in the lock");

bool NMethod::operator==(const NMethod& other) const
{
    bool ret = false;
    ret = (m_description == other.m_description);
    ret = (m_name == other.m_name);
    return ret;
}

bool NMethod::hasBody() const
{
    if (*this == POST)
        return true;
    else if (*this == PUT)
        return true;
    else
        return false;
}

NMethod NMethod::valueOf(const QString& methodName)
{
    QString normalizedMethodName(methodName.toUpper());

    if (normalizedMethodName == "CONNECT")
        return NMethod::CONNECT;
    else if (normalizedMethodName == "COPY")
        return NMethod::COPY;
    else if (normalizedMethodName == "DELETE")
        return NMethod::DELETE;
    else if (normalizedMethodName == "GET")
        return NMethod::GET;
    else if (normalizedMethodName == "HEAD")
        return NMethod::HEAD;
    else if (normalizedMethodName == "LOCK")
        return NMethod::LOCK;
    else if (normalizedMethodName == "MKCOL")
        return NMethod::MKCOL;
    else if (normalizedMethodName == "MOVE")
        return NMethod::MOVE;
    else if (normalizedMethodName == "OPTIONS")
        return NMethod::OPTIONS;
    else if (normalizedMethodName == "POST")
        return NMethod::POST;
    else if (normalizedMethodName == "PROPFIND")
        return NMethod::PROPFIND;
    else if (normalizedMethodName == "PROPPATCH")
        return NMethod::PROPPATCH;
    else if (normalizedMethodName == "PUT")
        return NMethod::PUT;
    else if (normalizedMethodName == "TRACE")
        return NMethod::TRACE;
    else if (normalizedMethodName == "UNLOCK")
        return NMethod::UNLOCK;
    else
        return NMethod(normalizedMethodName);
}
