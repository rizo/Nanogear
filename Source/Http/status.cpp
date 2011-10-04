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

#include "nstatus.h"

const NStatus NStatus::INFO_CONTINUE(100, "Continue", "The client should continue with"
        "its request");

const NStatus NStatus::CONNECTOR_ERROR_CONNECTION(1000, "Connection Error", "The connector "
        "failed to connect to the server");

const NStatus NStatus::CONNECTOR_ERROR_COMMUNICATION(1001, "Communication Error", "The connector "
        "failed to complete the communication with the server");

const NStatus NStatus::CONNECTOR_ERROR_INTERNAL(1002, "Internal Connector Error", "The connector "
        "encountered an unexpected condition which prevented it from fulfilling the request");

const NStatus NStatus::INFO_SWITCHING_PROTOCOL(101, "Switching Protocols", "The server is willing "
        "to change the application protocol being used on this connection");

const NStatus NStatus::INFO_PROCESSING(102, "Processing", "Interim response used to inform the "
        "client that the server has accepted the complete request, but has not yet completed it");

const NStatus NStatus::SUCCESS_OK(200, "OK", "The request has succeeded");

const NStatus NStatus::SUCCESS_CREATED(201, "Created", "The request has been fulfilled and "
        "resulted in a new resource being created");

const NStatus NStatus::SUCCESS_ACCEPTED(202, "Accepted", "The request has been accepted for "
        "processing, but the processing has not been completed");

const NStatus NStatus::SUCCESS_NON_AUTHORITATIVE(203, "Non-Authoritative Information", "The "
        "returned metainformation is not the definitive set as available from the origin server");

const NStatus NStatus::SUCCESS_NO_CONTENT(204, "No Content", "The server has fulfilled the request "
        "but does not need to return an entity-body, and might want to return "
        "updated metainformation");

const NStatus NStatus::SUCCESS_RESET_CONTENT(205, "Reset Content", "The server has fulfilled the "
        "request and the user agent should reset the document view which caused the request "
        "to be sent");

const NStatus NStatus::SUCCESS_PARTIAL_CONTENT(206, "Partial Content", "The server has fulfilled "
        "the partial get request for the resource");

const NStatus NStatus::SUCCESS_MULTI_STATUS(207, "Multi-Status", "Provides status for multiple "
        "independent operations");

const NStatus NStatus::REDIRECTION_MULTIPLE_CHOICES(300, "Multiple Choices", "The requested "
        "resource corresponds to any one of a set of representations");

const NStatus NStatus::REDIRECTION_PERMANENT(301, "Moved Permanently", "The requested resource has "
        "been assigned a new permanent URI");

const NStatus NStatus::REDIRECTION_FOUND(302, "Found", "The requested resource can be found under "
        "a different URI");

const NStatus NStatus::REDIRECTION_SEE_OTHER(303, "See Other", "The response to the request can be "
        "found under a different URI");

const NStatus NStatus::REDIRECTION_NOT_MODIFIED(304, "Not Modified", "The client has performed a "
        "conditional GET request and the document has not been modified");

const NStatus NStatus::REDIRECTION_USE_PROXY(305, "Use Proxy", "The requested resource must be "
        "accessed through the proxy given by the location field");

const NStatus NStatus::REDIRECTION_TEMPORARY(307, "Temporary Redirect", "The requested resource "
        "resides temporarily under a different URI");

const NStatus NStatus::CLIENT_ERROR_BAD_REQUEST(400, "Bad Request", "The request could not be "
        "understood by the server due to malformed syntax");

const NStatus NStatus::CLIENT_ERROR_UNAUTHORIZED(401, "Unauthorized", "The request requires user "
        "authentication");

const NStatus NStatus::CLIENT_ERROR_PAYMENT_REQUIRED(402, "Payment Required", "This code is "
        "reserved for future use");

const NStatus NStatus::CLIENT_ERROR_FORBIDDEN(403, "Forbidden", "The server understood the "
        "request, but is refusing to fulfill it");

const NStatus NStatus::CLIENT_ERROR_NOT_FOUND(404, "Not Found", "The server has not found anything "
        "matching the request URI");

const NStatus NStatus::CLIENT_ERROR_METHOD_NOT_ALLOWED(405, "Method Not Allowed", "The method "
        "specified in the request is not allowed for the resource identified by the request URI");

const NStatus NStatus::CLIENT_ERROR_NOT_ACCEPTABLE(406, "Not Acceptable", "The resource identified "
        "by the request is only capable of generating response entities which have content "
        "characteristics not acceptable according to the accept headers sent in the request");

const NStatus NStatus::CLIENT_ERROR_PROXY_AUTHENTIFICATION_REQUIRED(407, "Proxy Authentication "
        "Required", "This code is similar to Unauthorized, but indicates that the client must first"
        " authenticate itself with the proxy");

const NStatus NStatus::CLIENT_ERROR_REQUEST_TIMEOUT(408, "Request Timeout", "The client did not "
        "produce a request within the time that the server was prepared to wait");

const NStatus NStatus::CLIENT_ERROR_CONFLICT(409, "Conflict", "The request could not be completed "
        "due to a conflict with the current state of the resource");

const NStatus NStatus::CLIENT_ERROR_GONE(410, "Gone", "The requested resource is no longer "
        "available at the server and no forwarding address is known");

const NStatus NStatus::CLIENT_ERROR_LENGTH_REQUIRED(411, "Length Required", "The server refuses "
        "to accept the request without a defined content length");

const NStatus NStatus::CLIENT_ERROR_PRECONDITION_FAILED(412, "Precondition Failed", "The "
        "precondition given in one or more of the request header fields evaluated to false when "
        "it was tested on the server");

const NStatus NStatus::CLIENT_ERROR_REQUEST_ENTITY_TOO_LARGE(413, "Request Entity Too Large", "The "
        "server is refusing to process a request because the request entity is larger than the "
        "server is willing or able to process");

const NStatus NStatus::CLIENT_ERROR_REQUEST_URI_TOO_LONG(414, "Request URI Too Long", "The server "
        "is refusing to service the request because the request URI is longer than the server is"
        " willing to interpret");

const NStatus NStatus::CLIENT_ERROR_UNSUPPORTED_MEDIA_TYPE(415, "Unsupported Media Type", "The "
        "server is refusing to service the request because the entity of the request is in a format"
        "not supported by the requested resource for the requested method");

const NStatus NStatus::CLIENT_ERROR_REQUESTED_RANGE_NOT_SATISFIABLE(416, "Requested Range Not "
        "Satisfiable", "For byte ranges, this means that the first byte position were greater "
        "than the current length of the selected resource");

const NStatus NStatus::CLIENT_ERROR_EXPECTATION_FAILED(417, "Expectation Failed", "The expectation "
        "given in the request header could not be met by this server");

const NStatus NStatus::CLIENT_ERROR_UNPROCESSABLE_ENTITY(422, "Unprocessable Entity", "The server "
        "understands the content type of the request entity and the syntax of the request entity "
        "is correct but was unable to process the contained instructions");

const NStatus NStatus::CLIENT_ERROR_LOCKED(423, "Locked", "The source or destination resource of "
        "a method is locked");

const NStatus NStatus::CLIENT_ERROR_FAILED_DEPENDENCY(424, "Failed Dependency", "The method could "
        "not be performed on the resource because the requested action depended on another action "
        "and that action failed");

const NStatus NStatus::SERVER_ERROR_INTERNAL(500, "Internal Server Error", "The server encountered "
        "an unexpected condition which prevented it from fulfilling the request");

const NStatus NStatus::SERVER_ERROR_NOT_IMPLEMENTED(501, "Not Implemented", "The server does not "
        "support the functionality required to fulfill the request");

const NStatus NStatus::SERVER_ERROR_BAD_GATEWAY(502, "Bad Gateway", "The server, while acting as "
        "a gateway or proxy, received an invalid response from the upstream server it accessed in "
        "attempting to fulfill the request");

const NStatus NStatus::SERVER_ERROR_SERVICE_UNAVAILABLE(503, "Service Unavailable", "The server "
        "is currently unable to handle the request due to a temporary overloading or maintenance "
        "of the server");

const NStatus NStatus::SERVER_ERROR_GATEWAY_TIMEOUT(504, "Gateway Timeout", "The server, while "
        "acting as a gateway or proxy, did not receive a timely response from the upstream server "
        "specified by the URI (e.g. HTTP, FTP, LDAP) or some other auxiliary server (e.g. DNS) "
        "it needed to access in attempting to complete the request");

const NStatus NStatus::SERVER_ERROR_VERSION_NOT_SUPPORTED(505, "Version Not Supported", "The server"
        " does not support, or refuses to support, the protocol version that was used in the"
        "request message");

const NStatus NStatus::SERVER_ERROR_INSUFFICIENT_STORAGE(507, "Insufficient Storage", "The method "
        "could not be performed on the resource because the server is unable to store the "
        "representation needed to successfully complete the request");

bool NStatus::operator ==(const NStatus& other) const {
    bool ret = false;
    ret = (m_code == other.m_code);
    ret = (m_description == other.m_description);
    ret = (m_name == other.m_name);
    return ret;
}
