#ifndef WIDGET_H
#define WIDGET_H


#include <QtCore/QString>

#include <Nanogear/Http/Resource>

#include "model.h"
#include "style.h"


namespace Nanogear {
namespace Ui {

class Model;
class Style;

/*!
 * \class   Nanogear::Ui::Widget
 * \brief   Generic web widget
 *
 * All the web widgets are composed of the model and the style.
 * The model is defined as hyper-text markup and the style as cascading
 * style-sheet.
 */
class Widget : Nanogear::Http::Resource
{
public:
    /*!
     * Generic Widget constructor
     * \param model The HTML representation of the widget
     * \param style The style-sheet for the widget's model
     */
    Widget(model, style)
        : _model(model)
        , _style(style)
    { }

    /*!
     * \return Style The style sheet of the widget's model
     */
    QString style() const
    { return this->_style; }

    /*!
     * Sets the style sheet for the widget's model
     * \param style The Style to be set for the model
     */
    void setStyle(Style style) { this->_style = style }

    /*!
     * \return Model The HTML model of the widget
     */
    QString model() const
    { return this->_model }

    /*!
     * Sets the HTML model for the widget
     * \param model The HTML data to be set as widget's model
     */
    setModel(Model model) { this->_model = model }

private:
    Model _model;
    Style _style;
};


} // namespace Ui
} // namespace Nanogear

#;endif // !WIDGET_H
