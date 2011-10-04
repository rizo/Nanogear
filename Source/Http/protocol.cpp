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

#include "nprotocol.h"

// Initialize constants
const NProtocol NProtocol::HTTP("http", "HTTP", "HyperText Transfer Protocol", 80);

const NProtocol NProtocol::HTTPS("https", "HTTPS", "HyperText Transfer Protocol via SSL", 443);

const NProtocol NProtocol::FILE("file", "FILE", "FILE is a standard scheme to access to "
        "representations stored in the file system (locally most of the time).");

bool NProtocol::operator==(const NProtocol& other) const
{
    bool ret = false;
    ret = (m_name == other.m_name);
    ret = (m_description == other.m_description);
    ret = (m_defaultPort == other.m_defaultPort);
    return ret;
}
