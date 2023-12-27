#include "IntroductionSection.hpp"

#include <QTextList>

#include "../HeaderBar/HeaderBar.hpp"

IntroductionSection::IntroductionSection() {
    setObjectName("Thông tin hệ thống");
    setStyleSheet("background: transparent");
    setFrameStyle(QFrame::NoFrame);
    insertIntroduction();
}

void IntroductionSection::insertIntroduction() {
    insertTitle();
    insertBlock();
    insertFirstParagraph();
    insertBlock();
    insertSecondParagraph();
    insertBlock();
    insertImage();
    insertBlock();
    insertThirdParagraph();
}

void IntroductionSection::insertTitle() {
    blockFormat.setAlignment(Qt::AlignCenter);
    insertBlock();

    cursor->insertHtml(
        "<div style=\"font-size: 28px; font-weight: bold; color: red;\"> Thông "
        "tin hệ thống </div>"
    );

    blockFormat.setAlignment(Qt::AlignLeft);
}

void IntroductionSection::insertImage() {
    QTextImageFormat imageFormat;

    insertBlock();

    imageFormat.setName("assets/Diagram.png");
    cursor->insertImage(imageFormat);

    imageFormat.setName("assets/RealImage.png");
    cursor->insertImage(imageFormat, QTextFrameFormat::FloatRight);
}

void IntroductionSection::insertFirstParagraph() {
    insertBlock();

    cursor->insertHtml(
        "<div style=\"font-size: 20px;\">" + introduction.firstParagraph +
        "</div>"
    );
}

void IntroductionSection::insertSecondParagraph() {
    insertBlock();

    cursor->insertHtml(
        "<div style=\"font-size: 20px;\">" + introduction.secondParagraph +
        "</div>"
    );
}

void IntroductionSection::insertThirdParagraph() {
    insertBlock();

    cursor->insertHtml(
        "<div style=\"font-size: 20px; font-weight: bold;\">" +
        introduction.thirdParagraphTitle
    );

    QString reasonHTML = "<ol style=\"font-size: 20px;\">";

    for (const QString &reason : introduction.reasons) {
        reasonHTML += "<li>" + reason + "</li>";
    }

    reasonHTML += "</ol>";
    cursor->insertHtml(reasonHTML);
}
