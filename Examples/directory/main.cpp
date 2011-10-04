/*
 * Nanogear - C++ web development framework
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

#include <NApplication>
#include <NServer>

#include <NRouter>
#include <NResource>
#include <NRepresentation>
#include <NDirectoryResource>
#include <NStatus>

#include <ihttp/NHTTPServer>

class DirectoryApplication : public NApplication {
public:
    DirectoryApplication(int argc, char** argv) : NApplication(argc, argv) {}
    
    virtual NResource* createRoot() {
        NDirectoryResource* directory = new NDirectoryResource(".");
        directory->setIndexName("index.html");
        return directory;
    }
};

int main(int argc, char** argv) {
    DirectoryApplication app(argc, argv);
    app.setServer(new NHTTPServer());
    return app.exec();
}

