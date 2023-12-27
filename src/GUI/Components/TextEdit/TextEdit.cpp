#include "TextEdit.hpp"

TextEdit::TextEdit(QWidget *parent) : QTextEdit(parent) {
    setReadOnly(true);

    document = new QTextDocument(this);
    setDocument(document);

    cursor = new QTextCursor(document);
}

void TextEdit::insertBlock() { cursor->insertBlock(blockFormat); }
