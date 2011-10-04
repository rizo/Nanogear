#ifndef NSTYLE_H
#define NSTYLE_H

#include <QString>

#include <Nanogear/Http/Representation>

namespace Nanogear {
namespace Ui {

/*!
 * \class   Style
 * \brief   Style representation of the widget's model
 *
 * This class acts as a wrapper for style sheet and saves the data as a
 * representation of the widget resource.
 */
class Style : Nanogear::Http::Representation
{
public:
    /*!
     * \brief NStyle constructor. Initializes the resource representation style
     * \param str The style sheet data as a string
     */
    Style(QString str) : Representation(str, "text/css")
    { }

    /*!
     * \return  The CSS data as a string
     * \note    Same as `NStyle.data("text/css")`
     */
    QString css() const
    { return this->data("text/css"); }
};

} // namespace Ui
} // namespace Nanogear

#endif // !NSTYLE_H

