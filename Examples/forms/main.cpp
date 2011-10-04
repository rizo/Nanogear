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
#include <QDebug>

#include <NApplication>
#include <NStatus>
#include <NResponse>
#include <NRequest>
#include <NResource>
#include <NRepresentation>
#include <ihttp/NHTTPServer>


class FormsExample : public NResource
{
public:

    virtual void handleGet(const NRequest& request, NResponse& response)
    {
        QString parametersString;
        foreach (const QString& key, request.parameters().keys()) {
            parametersString += (key + " = " + request.parameters()[key] + "<br/>\n");
        }

        QString html = "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\" \"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">\n"
"<html xmlns=\"http://www.w3.org/1999/xhtml\" xml:lang=\"en\">\n"
"<head>\n"
"<title>Forms example</title>\n"
"</head>\n"
"<body>\n"
"<h2>Forms example</h2>\n"
"<h3>Get</h3>\n"
"<form name=\"input\" action=\"/method/get\" method=\"get\">\n"
"Field 1: <input type=\"text\" name=\"field1\" /><br/>\n"
"Field 2: <input type=\"password\" name=\"field2\" /><br/>\n"
"Radio 1: <input type=\"radio\" name=\"radio1\" /><br/>\n"
"<input type=\"submit\" value=\"Submit\" />\n"
"</form>\n"
"<h3>Post</h3>\n"
"<form name=\"input\" action=\"/method/post\" method=\"post\">\n"
"Field 1: <input type=\"text\" name=\"field1\" /><br/>\n"
"Field 2: <input type=\"password\" name=\"field2\" /><br/>\n"
"Radio 1: <input type=\"radio\" name=\"radio1\" /><br/>\n"
"<input type=\"submit\" value=\"Submit\" />\n"
"</form>\n"
"<hr/>\n"
"Method: %1<br/>\n"
"Args:<br/><br/>\n"
"%2\n"
"<hr/>\n"
"</body>\n"
"</html>\n";

    html.arg(request.method().name()).arg(parametersString);

        m_representation.setHtml(html);
        response.setStatus(NStatus::SUCCESS_OK);
        response.setRepresentation(&m_representation);
    }


    virtual void handlePost(const NRequest& request, NResponse& response)
    {
        handleGet(request, response);
    }

private:
    NRepresentation m_representation;
};



class FormsApplication : public NApplication
{
public:

    FormsApplication(int argc, char** argv)
        : NApplication(argc, argv)
    { }


    virtual NResource* createRoot()
    {
        return new FormsExample();
    }
};

int main(int argc, char** argv)
{
    FormsApplication app(argc, argv);
    app.setServer(new NHTTPServer());
    return app.exec();
}

