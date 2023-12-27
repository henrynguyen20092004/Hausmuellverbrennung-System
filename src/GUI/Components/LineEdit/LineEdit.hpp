#ifndef LINE_EDIT_HPP
#define LINE_EDIT_HPP

#include <QLineEdit>
#include <QString>
#include <QVBoxLayout>

#include "../TextLabel/TextLabel.hpp"

#define DEFAULT_TEXT "0"

class LineEdit : public QWidget {
   public:
    LineEdit(
        QWidget *parent, const QString &title, bool readOnly = false,
        const QString &defaultText = DEFAULT_TEXT
    );

    QString getText() const;
    void setText(const QString &text);
    void setDefaultText();
    void connectTextEditedSignal(const std::function<void()> &slot);
    void connectReturnPressedSignal(const std::function<void()> &slot);

   private:
    TextLabel *titleLabel;
    QLineEdit *lineEdit;
    QVBoxLayout *layout;
};

#endif
