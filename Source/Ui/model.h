#ifndef NMODEL_H
#define NMODEL_H

#include <QString>

#include <Nanogear/Http/Representation>

namespace Nanogear {
namespace Ui {


/*!
 * \class   Nanogear::Ui::Model
 * \brief   Structural representation of the widget
 *
 * This class holds the HTML content of the widget. The HTML is defined
 * as a representation for the widget resource.
 */
class Model : Nanogear::Http::Representation
{
public:
    /*!
     * \brief NModel constructor. Initializes the resource representation model
     * \param str The HTML data as a string
     */
    Model(QString str) : Representation(str, "application/xhtml+xml")
    { }
};

} // namespace Ui
} // namespace Nanogear


#endif // !NMODEL_H

