#ifndef HEADER_BAR_HPP
#define HEADER_BAR_HPP

#include <QBoxLayout>

#include "../../Components/TextLabel/TextLabel.hpp"

#define HEADER_BAR_HEIGHT 48

class HeaderBar : public QWidget {
   public:
    HeaderBar(QWidget *parent, const QString &titleText);

    void setTitle(const QString &titleText);

   private:
    TextLabel *title;
    QHBoxLayout *titleLayout;
};

#endif
