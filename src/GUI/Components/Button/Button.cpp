#include "Button.hpp"

Button::Button(QWidget *parent, const QString &content, const char *buttonStyle)
    : QPushButton(parent) {
    setText(content);
    setStyleSheet(buttonStyle);
}
