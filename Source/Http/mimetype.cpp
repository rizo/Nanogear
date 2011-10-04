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

#include "nmimetype.h"

#include <QString>

void NMimeType::fromString(const QString& type)
{
    m_whole = type;
    m_type.clear();
    m_subtype.clear();
}

const QString& NMimeType::toString() const
{
    return m_whole;
}


bool NMimeType::operator==(const NMimeType& type) const
{
    return m_whole == type.m_whole;
}

bool NMimeType::isConcrete() const
{
    return !m_whole.contains("*");
}


const QString& NMimeType::type() const
{
    if (m_type.isEmpty())
        const_cast<NMimeType*>(this)->m_type = m_whole.left(m_whole.indexOf('/'));

    return m_type;
}

const QString& NMimeType::subtype() const
{
    if (m_type.isEmpty())
        const_cast<NMimeType*>(this)->m_subtype = m_whole.right(m_whole.indexOf('/'));

    return m_subtype;
}

bool NMimeType::isCompatible(const NMimeType& other) const
{
    return other.m_whole.contains(m_whole) || \
           m_whole.contains(other.m_whole);
}
