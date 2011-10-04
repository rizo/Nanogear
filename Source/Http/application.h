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

// :s_N\([A-Z][a-z]\+\)_\1_g

#ifndef NAPPLICATION_H
#define NAPPLICATION_H

#include <QCoreApplication>

#include "nserver.h"
#include "nresponse.h"
#include "nresource.h"
#include "nrepresentation.h"

/*!
 * \class NApplication
 * \brief A Nanogear application
 *
 * This class represents a Nanogear application and it's used to handle a set
 * of dependant resources.
 * It is responsible for starting the event loop and the attached connector.
 */
class NApplication : public QCoreApplication, public NResource
{
public:
    /*!
     * Initialize this Nanogear application
     *
     * The argc and argv arguments are processed by the application, and made
     * available in a more convenient form by the arguments() function.
     *
     * Warning: The data pointed to by argc and argv must stay valid for the
     * entire lifetime of the QCoreApplication object.
     */
    NApplication(int argc, char** argv) : QCoreApplication(argc, argv) {}

    /*!
     * Attach a server to this application. The server is automatically started
     * when calling exec()
     * \param server a pointer to a concrete implementation of the server class
     */
    void setServer(NServer* server) {
        m_server = server;
    }

    /*!
     * \return The currently attached server
     */
    NServer* server() const {
        return m_server;
    }

    /*!
     * Every application must implement this function to create the root resource in the heap
     * (which will answer requests to every URI)
     * \note The instance of the object returned by this method is automatically deleted
     *       by a Server implementation after handling the request.
     * \return A pointer to the created resource
     */
    virtual NResource* createRoot() {
        return 0; // FIXME: dangerous
    };

    /*!
     * Retrieve an instance of this Nanogear application
     * \return A pointer to the current instance
     */
    static NApplication* instance() {
        return static_cast<NApplication*>(QCoreApplication::instance());
    }

    /*!
     * Start this Nanogear application. This method will also call the
     * Server::start() method for you.
     * \return The value set to exit() (which is 0 if you call quit())
     */
    int exec() {
        m_server->start();
        return QCoreApplication::exec();
    }

private:
    NServer* m_server;
};

#endif /* NAPPLICATION_H */
