#include "TextLabel.hpp"

TextLabel::TextLabel(
    QWidget *parent, const QString &content, const char *textLabelStyle
)
    : QLabel(parent) {
    setText(content);
    setStyleSheet(textLabelStyle);
    setWordWrap(true);
    setAlignment(Qt::AlignCenter);
}
