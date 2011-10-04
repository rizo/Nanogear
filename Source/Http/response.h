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

#ifndef NRESPONSE_H
#define NRESPONSE_H

#include <QObject>
#include <QDateTime>

#include "nstatus.h"

class NRepresentation;

/*!
 * \class NResponse
 * \brief Encapsulates a response to the client
 *
 * A Response object represents a server response. Resources usually have the
 * task to fill a Response object which will be sent back to the client by a
 * concrete implementation of Server
 */

class NResponse : public QObject
{
public:
    /*!
     * Initializes an invalid response object
     */
    NResponse() : m_representation(0) {}

    /*!
     * Set the response status code
     * \param status The response status code
     */
    void setStatus(const NStatus& status)
    { m_status = status; }

    /*!
     * \return The response' status code
     */
    const NStatus& status()
    { return m_status; }

    /*!
     * Set the representation attached to this Response
     * \param representation A pointer to a Representation object
     */
    void setRepresentation(const NRepresentation* representation)
    { m_representation = representation; }

    /*!
     * \return The representation attached to this Response
     */
    const NRepresentation* representation() const
    { return m_representation; }

    /*!
     * Set the expiration date for this Response
     * \param expires A QDateTime representing the expiration date
     */
    void setExpirationDate(const QDateTime& expires)
    { m_expires = expires; }

    /*!
     * \return the expiration date of this Response
     */
    const QDateTime& expirationDate() const
    { return m_expires; }

private:
    NStatus m_status;
    const NRepresentation* m_representation;
    QDateTime m_expires;
};

#endif /* NRESPONSE_H */
