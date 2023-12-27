#include "SwitchSectionButton.hpp"

#include "../HeaderBar/HeaderBar.hpp"

SwitchSectionButton::SwitchSectionButton(
    QWidget *parent, QStackedWidget *stackedWidget
)
    : QWidget(parent) {
    setGeometry(-10, HEADER_BAR_HEIGHT - 10, 420, 40);

    layout = new QHBoxLayout(this);

    for (int i = 0; i < stackedWidget->count(); i++) {
        buttons.emplace_back(new Button(
            this, stackedWidget->widget(i)->objectName(), "font-size: 16px;"
        ));
        buttons[i]->setFixedSize(140, 40);
        layout->addWidget(buttons[i]);

        connect(buttons[i], CLICKED, [=]() {
            stackedWidget->setCurrentIndex(i);
        });
    }
}
