#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <QPushButton>

#define CLICKED &QPushButton::clicked

class Button : public QPushButton {
   public:
    Button(QWidget *parent, const QString &content, const char *buttonStyle);
};

#endif
