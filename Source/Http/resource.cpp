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

#include "nresource.h"

#include "nmethod.h"
#include "nstatus.h"
#include "nrequest.h"
#include "nresponse.h"

void NResource::handleRequest(const NRequest& request, NResponse& response)
{
    if (request.method() == NMethod::GET) {
        handleGet(request, response);
    } else if (request.method() == NMethod::PUT) {
        handlePut(request, response);
    } else if (request.method() == NMethod::POST) {
        handlePost(request, response);
    } else if (request.method() == NMethod::OPTIONS) {
        handleOptions(request, response);
    } else if (request.method() == NMethod::DELETE) {
        handleDelete(request, response);
    } else if (request.method() == NMethod::HEAD) {
        handleHead(request, response);
    } else {
        response.setStatus(NStatus::CLIENT_ERROR_NOT_FOUND);
    }
}


