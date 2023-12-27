#include "LineEdit.hpp"

LineEdit::LineEdit(
    QWidget *parent, const QString &title, bool readOnly,
    const QString &defaultText
)
    : QWidget(parent) {
    setFixedHeight(80);

    titleLabel =
        new TextLabel(this, title, "font-size: 24px; font-weight: bold;");
    titleLabel->setAlignment(Qt::AlignLeft);

    lineEdit = new QLineEdit(this);
    lineEdit->setText(defaultText);
    lineEdit->setStyleSheet("font-size: 20px;");
    lineEdit->setReadOnly(readOnly);

    layout = new QVBoxLayout(this);
    layout->addWidget(titleLabel);
    layout->addWidget(lineEdit);
}

QString LineEdit::getText() const { return lineEdit->text(); }

void LineEdit::setText(const QString &text) { lineEdit->setText(text); }

void LineEdit::setDefaultText() { lineEdit->setText(DEFAULT_TEXT); }

void LineEdit::connectTextEditedSignal(const std::function<void()> &slot) {
    connect(lineEdit, &QLineEdit::textEdited, slot);
}

void LineEdit::connectReturnPressedSignal(const std::function<void()> &slot) {
    connect(lineEdit, &QLineEdit::returnPressed, slot);
}
