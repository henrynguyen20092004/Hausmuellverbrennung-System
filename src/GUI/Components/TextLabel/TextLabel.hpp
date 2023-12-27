#ifndef TEXT_LABEL_HPP
#define TEXT_LABEL_HPP

#include <QLabel>

class TextLabel : public QLabel {
   public:
    TextLabel(
        QWidget *parent, const QString &content, const char *textLabelStyle
    );
};

#endif
