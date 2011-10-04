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

#ifndef NDIRECTORYRESOURCE_H
#define NDIRECTORYRESOURCE_H

#include <QDir>
#include <QString>

#include "nresource.h"
#include "nrepresentation.h"

class NRequest;

class NResponse;

/*!
 * \class NDirectoryResource
 * \brief A resource mapping files under a directory to URI paths
 *
 * NDirectoryResource can be used to provide filesystem access to the clients.
 *
 * A typical use-case of this class is to send images, scripts and other data
 * along with an HTML page to the client or just let clients (typically
 * web browsers) browse a directory.
 *
 * NDirectoryResource accepts a directory as the 'root' directory and every file
 * contained will be mapped to an URI path.
 */
class NDirectoryResource : public NResource
{
public:
    NDirectoryResource(const QString& root);

    /*!
     * Set the root directory on the filesystem
     * \param root An absolute or relative path to a directory on the filesystem
     */
    void setRoot(const QString& root)
    { m_root = QDir(root); }

    /*!
     * \return The absolute path to the root directory
     */
    QString root() const
    { return m_root.absolutePath(); }

    /*!
     * Set the index file name
     * \param indexName Index file name
     */
    void setIndexName(const QString& indexName)
    { m_indexName = indexName; }

    /*!
     * \return The index file name
     */
    const QString& indexName() const
    { return m_indexName; }

    /*!
     * Set this to true to display a directory index when no index file is
     * found. If false, this Resource will answer with Status::Forbidden
     * \param indexAllowed Whether or not allow directory index generation
     */
    void setIndexAllowed(bool indexAllowed)
    { m_indexAllowed = indexAllowed; }

    /*!
     * \return True if directory index generation is allowed
     */
    bool isIndexAllowed() const
    { return m_indexAllowed; }

    /*!
     * \return a modifiable QHash mapping file extensions to MIME types
     */
    QHash<QString, QString>& mimeMappings()
    { return m_mimeMappings; }

protected:
    /*!
     * Handle GET request. If a file is requested do a MIME type lookup using
     * libmagic. If a directory is requested first look for an index file and
     * show it (if available) otherwise show a directory listing if allowed
     * or send a 403 when this resource is not allowed to send directory
     * listings.
     */
    virtual void handleGet(const NRequest& request, NResponse& response);

private:
    /*!
     * Internal method used to send a file back to the client
     * \param pathInfo A QFileInfo reference of the requested file
     * \param response A reference to the NResponse object passed to handleGet
     */
    void representFile(const QFileInfo& pathInfo, NResponse& response);

    QDir m_root;
    bool m_indexAllowed;
    QString m_indexName;
    QString m_xhtmlRepr;
    QHash<QString, QString> m_mimeMappings;

    NRepresentation m_notAllowed;
    NRepresentation m_directoryIndex;
    NRepresentation m_rawFile;
};

#endif /* NDIRECTORYRESOURCE_H */
