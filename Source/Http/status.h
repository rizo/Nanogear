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

#ifndef NSTATUS_H
#define NSTATUS_H

#include <QString>

#include "nmetadata.h"

/*!
 * \class NStatus
 * \brief Response status code
 *
 * This class is used to send response status codes to the clients.
 * Status codes conform to HTTP 1.1 status codes.
 */
class NStatus : public NMetadata
{
public:
    /*!
     * Default constructor
     */
    NStatus() {}
    
    /*!
     * Construct a Status by providing its code
     * \param code The status code
     */
    NStatus(int code) : m_code(code) {}

    /*!
     * \param code The status code
     * \param name The status name
     * \param description Short status description
     */
    NStatus(int code, const QString& name, const QString& description) :
        NMetadata(name, description), m_code(code) {}

    /*!
     * \return The status code
     */
    int code() const
    { return m_code; }

    /*!
     * \return True if both objects are the same
     */
    bool operator==(const NStatus& other) const;

    // Statuses
    /*!
     * The request could not be understood by the server due to malformed
     * syntax.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.4.1">HTTP RFC - 10.4.1 400 Bad Request</a>
     */
    static const NStatus CLIENT_ERROR_BAD_REQUEST;

    /*!
     * The request could not be completed due to a conflict with the current
     * state of the resource (as experienced in a version control system).
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.4.10">HTTP RFC - 10.4.10 409 Conflict</a>
     */
    static const NStatus CLIENT_ERROR_CONFLICT;

    /*!
     * The user agent expects some behaviour of the server (given in an Expect
     * request-header field), but this expectation could not be met by this
     * server.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.4.18">HTTP RFC - 10.4.18 417 Expectation Failed</a>
     */
    static const NStatus CLIENT_ERROR_EXPECTATION_FAILED;

    /*!
     * This status code means that the method could not be performed on the
     * resource because the requested action depended on another action and that
     * action failed.
     *
     * \see <a href="http://www.webdav.org/specs/rfc2518.html#STATUS_424">WEBDAV RFC - 10.5 424 Failed Dependency</a>
     */
    static const NStatus CLIENT_ERROR_FAILED_DEPENDENCY;

    /*!
     * The server understood the request, but is refusing to fulfill it as it
     * could be explained in the entity.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.4.4">HTTP RFC - 10.4.4 403 Forbidden</a>
     */
    static const NStatus CLIENT_ERROR_FORBIDDEN;

    /*!
     * The requested resource is no longer available at the server and no
     * forwarding address is known.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.4.11">HTTP RFC - 10.4.11 410 Gone</a>
     */
    static const NStatus CLIENT_ERROR_GONE;

    /*!
     * The server refuses to accept the request without a defined
     * Content-Length.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.4.12">HTTP RFC - 10.4.12 411 Length Required</a>
     */
    static const NStatus CLIENT_ERROR_LENGTH_REQUIRED;

    /*!
     * The source or destination resource of a method is locked (or temporarily
     * involved in another process).
     *
     * \see <a href="http://www.webdav.org/specs/rfc2518.html#STATUS_423">WEBDAV RFC - 10.4 423 Locked</a>
     */
    static const NStatus CLIENT_ERROR_LOCKED;

    /*!
     * The method specified in the Request-Line is not allowed for the resource
     * identified by the Request-URI.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.4.6">HTTP RFC - 10.4.6 405 Method Not Allowed</a>
     */
    static const NStatus CLIENT_ERROR_METHOD_NOT_ALLOWED;

    /*!
     * The resource identified by the request is only capable of generating
     * response entities whose content characteristics do not match the user's
     * requirements (in Accept* headers).
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.4.7">HTTP RFC - 10.4.7 406 Not Acceptable</a>
     */
    static const NStatus CLIENT_ERROR_NOT_ACCEPTABLE;

    /*!
     * The server has not found anything matching the Request-URI or the server
     * does not wish to reveal exactly why the request has been refused, or no
     * other response is applicable.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.4.5">HTTP RFC - 10.4.5 404 Not Found</a>
     */
    static const NStatus CLIENT_ERROR_NOT_FOUND;

    /*!
     * This code is reserved for future use.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.4.3">HTTP RFC - 10.4.3 402 Payment Required</a>
     */
    static const NStatus CLIENT_ERROR_PAYMENT_REQUIRED;

    /*!
     * Sent by the server when the user agent asks the server to carry out a
     * request under certain conditions that are not met.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.4.13">HTTP RFC - 10.4.13 412 Precondition Failed</a>
     */
    static const NStatus CLIENT_ERROR_PRECONDITION_FAILED;

    /*!
     * This code is similar to 401 (Unauthorized), but indicates that the client
     * must first authenticate itself with the proxy.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.4.8">HTTP RFC - 10.4.8 407 Proxy Authentication Required</a>
     */
    static const NStatus CLIENT_ERROR_PROXY_AUTHENTIFICATION_REQUIRED;

    /*!
     * The server is refusing to process a request because the request entity is
     * larger than the server is willing or able to process.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.4.14">HTTP RFC - 10.4.14 413 Request Entity Too Large</a>
     */
    static const NStatus CLIENT_ERROR_REQUEST_ENTITY_TOO_LARGE;

    /*!
     * Sent by the server when an HTTP client opens a connection, but has never
     * sent a request (or never sent the blank line that signals the end of the
     * request).
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.4.9">HTTP RFC - 10.4.9 408 Request Timeout</a>
     */
    static const NStatus CLIENT_ERROR_REQUEST_TIMEOUT;

    /*!
     * The server is refusing to service the request because the Request-URI is
     * longer than the server is willing to interpret.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.4.15">HTTP RFC - 10.4.15 414 Request-URI Too Long</a>
     */
    static const NStatus CLIENT_ERROR_REQUEST_URI_TOO_LONG;
    
    /*!
     * The request includes a Range request-header field and the selected
     * resource is too small for any of the byte-ranges to apply.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.4.17">HTTP RFC - 10.4.17 416 Requested Range Not Satisfiable</a>
     */
    static const NStatus CLIENT_ERROR_REQUESTED_RANGE_NOT_SATISFIABLE;

    /*!
     * The request requires user authentication.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.4.2">HTTP RFC - 10.4.2 401 Unauthorized</a>
     */
    static const NStatus CLIENT_ERROR_UNAUTHORIZED;

    /*!
     * This status code means the server understands the content type of the
     * request entity (syntactically correct) but was unable to process the
     * contained instructions.
     *
     * \see <a href="http://www.webdav.org/specs/rfc2518.html#STATUS_422">WEBDAV RFC - 10.3 422 Unprocessable Entity</a>
     */
    static const NStatus CLIENT_ERROR_UNPROCESSABLE_ENTITY;

    /*!
     * The server is refusing to service the request because the entity of the
     * request is in a format not supported by the requested resource for the
     * requested method.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.4.16">HTTP RFC - 10.4.16 415 Unsupported Media Type</a>
     */
    static const NStatus CLIENT_ERROR_UNSUPPORTED_MEDIA_TYPE;

    /*!
     * A client connector faces an error during the communication with the
     * remote server (interruption, timeout, etc).
     */
    static const NStatus CONNECTOR_ERROR_COMMUNICATION;

    /*!
     * A client connector can not connect to the remote server.
     */
    static const NStatus CONNECTOR_ERROR_CONNECTION;

    /*!
     * Generic status code sent by a client connector when an error occurs
     * during the process of a request to its server or the process of a
     * response to its client.
     */
    static const NStatus CONNECTOR_ERROR_INTERNAL;

    /*!
     * This interim response (the client has to wait for the const response) is
     * used to inform the client that the initial part of the request has been
     * received and has not yet been rejected or completed by the server.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.1.1">HTTP RFC - 10.1.1 100 Continue</a>
     */
    static const NStatus INFO_CONTINUE;

    /*!
     * This interim response is used to inform the client that the server has
     * accepted the complete request, but has not yet completed it since the
     * server has a reasonable expectation that the request will take
     * significant time to complete.
     *
     * \see <a href="http://www.webdav.org/specs/rfc2518.html#STATUS_102">WEBDAV RFC - 10.1 102 Processing</a>
     */
    static const NStatus INFO_PROCESSING;

    /*!
     * The server understands and is willing to comply with the client's
     * request, via the Upgrade message header field, for a change in the
     * application protocol being used on this connection.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.1.2">HTTP RFC - 10.1.1 101 Switching Protocols</a>
     */
    static const NStatus INFO_SWITCHING_PROTOCOL;

    /*!
     * The requested resource resides temporarily under a different URI which
     * should not be used for future requests by the client (use status codes
     * 303 or 307 instead since this status has been manifestly misused).
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.3.3">HTTP RFC - 10.3.3 302 Found</a>
     */
    static const NStatus REDIRECTION_FOUND;

    /*!
     * The server lets the user agent choosing one of the multiple
     * representations of the requested resource, each representation having its
     * own specific location provided in the response entity.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.3.1">HTTP RFC - 10.3.1 300 Multiple Choices</a>
     */
    static const NStatus REDIRECTION_MULTIPLE_CHOICES;

    /*!
     * NStatus code sent by the server in response to a conditional GET request
     * in case the document has not been modified.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.3.5">HTTP RFC - 10.3.5 304 Not Modified</a>
     */
    static const NStatus REDIRECTION_NOT_MODIFIED;

    /*!
     * The requested resource has been assigned a new permanent URI and any
     * future references to this resource SHOULD use one of the returned URIs.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.3.2">HTTP RFC - 10.3.2 301 Moved Permanently</a>
     */
    static const NStatus REDIRECTION_PERMANENT;

    /*!
     * The response to the request can be found under a different URI and SHOULD
     * be retrieved using a GET method on that resource.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.3.4">HTTP RFC - 10.3.4 303 See Other</a>
     */
    static const NStatus REDIRECTION_SEE_OTHER;

    /*!
     * The requested resource resides temporarily under a different URI which
     * should not be used for future requests by the client.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.3.8">HTTP RFC - 10.3.8 307 Temporary Redirect</a>
     */
    static const NStatus REDIRECTION_TEMPORARY;

    /*!
     * The requested resource MUST be accessed through the proxy given by the
     * Location field.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.3.6">HTTP RFC - 10.3.6 305 Use Proxy</a>
     */
    static const NStatus REDIRECTION_USE_PROXY;

    /*!
     * The server, while acting as a gateway or proxy, received an invalid
     * response from the upstream server it accessed in attempting to fulfill
     * the request.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.5.3">HTTP RFC - 10.5.3 502 Bad Gateway</a>
     */
    static const NStatus SERVER_ERROR_BAD_GATEWAY;

    /*!
     * The server, while acting as a gateway or proxy, could not connect to the
     * upstream server.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.5.5">HTTP RFC - 10.5.5 504 Gateway Timeout</a>
     */
    static const NStatus SERVER_ERROR_GATEWAY_TIMEOUT;

    /*!
     * This status code means the method could not be performed on the resource
     * because the server is unable to store the representation needed to
     * successfully complete the request.
     *
     * \see <a href="http://www.webdav.org/specs/rfc2518.html#STATUS_507">WEBDAV RFC - 10.6 507 Insufficient Storage</a>
     */
    static const NStatus SERVER_ERROR_INSUFFICIENT_STORAGE;

    /*!
     * The server encountered an unexpected condition which prevented it from
     * fulfilling the request.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.5.1">HTTP RFC - 10.5.1 500 Internal Server Error</a>
     */
    static const NStatus SERVER_ERROR_INTERNAL;

    /*!
     * The server does not support the functionality required to fulfill the
     * request.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.5.2">HTTP * RFC - 10.5.2 501 Not Implemented</a>
     */
    static const NStatus SERVER_ERROR_NOT_IMPLEMENTED;

    /*!
     * The server is currently unable to handle the request due to a temporary
     * overloading or maintenance of the server.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.5.4">HTTP RFC - 10.5.4 503 Service Unavailable</a>
     */
    static const NStatus SERVER_ERROR_SERVICE_UNAVAILABLE;

    /*!
     * The server does not support, or refuses to support, the HTTP protocol
     * version that was used in the request message.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.5.6">HTTP RFC - 10.5.6 505 HTTP Version Not Supported</a>
     */
    static const NStatus SERVER_ERROR_VERSION_NOT_SUPPORTED;

    /*!
     * The request has been accepted for processing, but the processing has not
     * been completed.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.2.3">HTTP RFC - 10.2.3 202 Accepted</a>
     */
    static const NStatus SUCCESS_ACCEPTED;

    /*!
     * The request has been fulfilled and resulted in a new resource being
     * created.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.2.2">HTTP RFC - 10.2.2 201 Created</a>
     */
    static const NStatus SUCCESS_CREATED;

    /*!
     * This response is used to inform the client that the HTTP response entity
     * contains a set of status codes generated during the method invocation.
     *
     * \see <a href="http://www.webdav.org/specs/rfc2518.html#STATUS_207">WEBDAV RFC - 10.2 207 Multi-Status</a>
     */
    static const NStatus SUCCESS_MULTI_STATUS;

    /*!
     * The server has fulfilled the request but does not need to return an
     * entity-body (for example after a DELETE), and might want to return
     * updated metainformation.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.2.5">HTTP RFC - 10.2.5 204 No Content</a>
     */
    static const NStatus SUCCESS_NO_CONTENT;

    /*!
     * The request has succeeded but the returned metainformation in the
     * entity-header do not come from the origin server, but is gathered from a
     * local or a third-party copy.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.2.4">HTTP RFC - 10.2.4 203 Non-Authoritative Information</a>
     */
    static const NStatus SUCCESS_NON_AUTHORITATIVE;

    /*!
     * The request has succeeded.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.2.1">HTTP RFC - 10.2.1 200 OK</a>
     */
    static const NStatus SUCCESS_OK;

    /*!
     * The server has fulfilled the partial GET request for the resource
     * assuming the request has included a Range header field indicating the
     * desired range.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.2.7">HTTP RFC - 10.2.7 206 Partial Content</a>
     */
    static const NStatus SUCCESS_PARTIAL_CONTENT;

    /*!
     * The server has fulfilled the request and the user agent SHOULD reset the
     * document view which caused the request to be sent.
     *
     * \see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html#sec10.2.6">HTTP RFC - 10.2.6 205 Reset Content</a>
     */
    static const NStatus SUCCESS_RESET_CONTENT;
private:
    int m_code;
};

#endif /* NSTATUS_H */
