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

#ifndef NROUTER_H
#define NROUTER_H

#include <QHash>
#include <QString>
#include <QPointer>

#include "nresource.h"
#include "nrepresentation.h"

class NRequest;

class NResponse;

/*!
 * \class NRouter
 * \brief A resource that can route requests based on a URI pattern
 *
 * A router is simply a Resource which stores a mapping of URI paths to
 * heap-allocated Resource instances (using a guarded pointer)
 *
 * \note Router's destructor will automatically check if the attached resources
 *       are still valid pointers, if yes it deletes the referencing objects.
 */

class NRouter : public NResource
{
public:
    NRouter() : m_notFound("<h2>404 - Not found</h2>", "text/html") {}

    /*!
     * This destructor will automatically destroy the objects attached to
     * this Router
     */
    ~NRouter();

    /*!
     * This method is used internally to dispatch request to routed classes
     */
    void handleRequest(const NRequest&, NResponse&);

    /*!
     * Attach a resource to this Router
     * \param path The URI path on which the attached resource will respond to requests
     * \param resource A pointer to a Resource object
     */
    void attach(const QString& path, QPointer<NResource> resource)
    { m_routes[path] = resource; }

    /*!
     * \return A modifiable QHash representing the routes
     */
    QHash<QString, QPointer<NResource> >& routes()
    { return m_routes; }

private:
    QHash<QString, QPointer<NResource> > m_routes;
    NRepresentation m_notFound;
};

#endif /* NROUTER_H */
