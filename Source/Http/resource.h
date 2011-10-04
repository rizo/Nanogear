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

#ifndef NRESOURCE_H
#define NRESOURCE_H

#include "nuniform.h"

/*!
 * \class NResource
 * \brief The conceptual target of an hypertext reference
 *
 * "The key abstraction of information in REST is a resource. Any information
 * that can be named can be a resource: a document or image, a temporal service
 * (e.g. "today's weather in Los Angeles"), a collection of other resources,
 * a non-virtual object (e.g. a person), and so on. In other words, any concept
 * that might be the target of an author's hypertext reference must fit within
 * the definition of a resource. A resource is a conceptual mapping to a set of
 * entities, not the entity that corresponds to the mapping at any particular
 * point in time."
 *
 * \see Roy Fielding's dissertation at:
 *     http://roy.gbiv.com/pubs/dissertation/rest_arch_style.htm#sec_5_2_1_1
 */
class NResource : public NUniform {
public:
    /*!
     * \return True if this resource was started
     */
    bool isStarted()
    { return m_started; }

    /*!
     * Reimplement this method to define how to start this resource.
     * This is mostly used internally by other classes.
     */
    virtual void start() {}

    /*!
     * Re-implement this method to define how to stop this resource.
     */
    virtual void stop() {}

    /*!
     * This method is used internally to dispatch the request to the
     * appropriate handler
     * \param request a const reference to a Request object
     * \param response a reference to the Response object built by the Connector
     * \return a response object
     */
    virtual void handleRequest(const NRequest& request, NResponse& response);

private:
    bool m_started;
};

#endif /* NRESOURCE_H */
