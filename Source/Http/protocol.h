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

#ifndef NPROTOCOL_H
#define	NPROTOCOL_H

#include <QString>

#include "nmetadata.h"

/*!
 * \class NProtocol
 * \brief Wrap some common protocols in a class
 */
class NProtocol : public NMetadata {
public:
    /*!
     * Default constructor
     */
    NProtocol() : m_defaultPort(0) {}

    /*!
     * @param name The protocol's name
     */
    NProtocol(const QString& name) : NMetadata(name), m_defaultPort(0) {}

    /*!
     * @param name The protocol's name
     * @param description The protocol's description
     */
    NProtocol(const QString& name, const QString& description) : NMetadata(name, description),
        m_defaultPort(0) {}

    /*!
     * @param name The protocol's name
     * @param description The protocol's description
     * @param defaultPort The protocol's default port
     */
    NProtocol(const QString& name, const QString& description, int defaultPort) :
        NMetadata(name, description), m_defaultPort(defaultPort) {}

    /*!
     * @param schemeName The scheme name (usually the part before '://' in a URI :-)
     * @param name The protocol's name
     * @param description The protocol's description
     * @param defaultPort The protocol's default port
     */
    NProtocol(const QString& schemeName, const QString& name, const QString& description,
            int defaultPort) : NMetadata(name, description), m_schemeName(schemeName),
            m_defaultPort(defaultPort) {}

   /*!
    * @param schemeName The scheme name (usually the part before '://' in a URI :-)
    * @param name The protocol's name
    * @param description The protocol's description
    */
    NProtocol(const QString& schemeName, const QString& name, const QString& description) :
           NMetadata(name, description), m_schemeName(schemeName) {}

    bool operator==(const NProtocol& other) const;

    //! The HTTP protocol
    static const NProtocol HTTP;

    //! The HTTP protocol over SSL
    static const NProtocol HTTPS;

    //! The file protocol used for local resources
    static const NProtocol FILE;
private:
    QString m_schemeName;
    int m_defaultPort;
};

#endif	/* NPROTOCOL_H */

