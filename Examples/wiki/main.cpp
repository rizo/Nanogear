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


#include <QString>

#include <NApplication>
#include <NResource>
#include <NRequest>
#include <NResponse>
#include <NRepresentation>
#include <NStatus>
#include <NRouter>
#include <ihttp/NHTTPServer>



class RootResource : public NResource
{
public:

    RootResource() : m_representation("<h1>Simple example</h1><br/><a href=\"/2\">Another resource</a>", "text/html")
    { }

    virtual void handleGet(const NRequest& request, NResponse& response)
    {
        Q_UNUSED(request)

        response.setStatus(NStatus::SUCCESS_OK);
        response.setRepresentation(&m_representation);
    }


private:
    NRepresentation m_representation;
};



class SecondResource : public NResource
{
public:

    SecondResource() : m_representation("<h1>Another resource</h1>", "text/html")
    { }

    virtual void handleGet(const NRequest& request, NResponse& response)
    {
        Q_UNUSED(request)

        response.setStatus(NStatus::SUCCESS_OK);
        response.setRepresentation(&m_representation);
    }

private:
    NRepresentation m_representation;
};



class SimpleApplication : public NApplication
{
public:

    SimpleApplication(int argc, char** argv) : NApplication(argc, argv)
    { }

    virtual NResource* createRoot()
    {
        RootResource* root = new RootResource();
        SecondResource* secondResource = new SecondResource();

        NRouter* router = new NRouter();
        router->attach("/", root);
        router->attach("/2", secondResource);

        return router;
    }
};



int main(int argc, char** argv)
{
    SimpleApplication app(argc, argv);
    app.setServer(new NHTTPServer());
    return app.exec();
}

