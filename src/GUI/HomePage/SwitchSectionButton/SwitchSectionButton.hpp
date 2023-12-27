#ifndef SWITCH_SECTION_BUTTON_HPP
#define SWITCH_SECTION_BUTTON_HPP

#include <QHBoxLayout>
#include <QStackedWidget>

#include "../../Components/Button/Button.hpp"

class SwitchSectionButton : public QWidget {
   public:
    SwitchSectionButton(QWidget *parent, QStackedWidget *stackedWidget);

   private:
    std::vector<Button *> buttons;
    QHBoxLayout *layout;
};

#endif
