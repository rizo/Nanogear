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

#include "nrouter.h"

#include <QDebug>

#include "nrequest.h"
#include "nresponse.h"

NRouter::~NRouter()
{
    QHash<QString, QPointer<NResource> >::ConstIterator it;

    for (it = m_routes.begin(); it != m_routes.end(); ++it) {
        if (!it->isNull()) {
            qDebug() << Q_FUNC_INFO << "Deleting resource attached to" << it.key();
            delete(*it);
        }
    }
}


void NRouter::handleRequest(const NRequest& request, NResponse& response)
{
    bool found = false;

    if (!m_routes.value(request.resourceRef()).isNull()) {
        // Direct match found, get the class pointer and make it handle the request
        qDebug() << Q_FUNC_INFO << "Found a direct match with requested path ("
        << request.resourceRef() << ")";
        m_routes.value(request.resourceRef())->handleRequest(request, response);
        found = true;
    }

    if (!found) {
        qDebug() << Q_FUNC_INFO << "Couldn't find any direct match (404)";
        response.setStatus(NStatus::CLIENT_ERROR_NOT_FOUND);
        response.setRepresentation(&m_notFound);
    }
}
