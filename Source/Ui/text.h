#ifndef TEXT_H
#define TEXT_H


#include <QtCore/QString>

//#include "widget.h"


namespace Nanogear {
namespace Ui {

class Widget;

/*!
 * \brief   A simple widget for displaying text
 * This simple widget is a wrapper for the HTML text elements.
 * By default there are no extra styling of the text. That is, the model
 * is sent as it is. To format the text, the css style should be
 * attached to the widget.
 */
class Text : Widget
{
public:
    WText() { }

    /*!
     * \brief Returns the text
     * This function returns the containing text of the WText widget. If
     * the format was set to Ng.XHTMLText Ng.PlainText
     */
    QString text() const
    { return this->model(); }
};

} // namespace Ui
} // namespace Nanogear




#endif // !TEXT_H
