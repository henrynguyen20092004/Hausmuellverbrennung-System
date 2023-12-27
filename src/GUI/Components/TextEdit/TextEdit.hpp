#ifndef TEXT_EDIT_HPP
#define TEXT_EDIT_HPP

#include <QTextCursor>
#include <QTextDocument>
#include <QTextEdit>

class TextEdit : public QTextEdit {
   public:
    TextEdit(QWidget *parent = nullptr);

   protected:
    QTextBlockFormat blockFormat;
    QTextCursor *cursor;

    void insertBlock();

   private:
    QTextDocument *document;
};

#endif
