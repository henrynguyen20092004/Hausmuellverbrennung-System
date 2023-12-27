#ifndef INTRODUCTION_HPP
#define INTRODUCTION_HPP

#include <QStringList>

struct Introduction {
    QStringList reasons;
    QString firstParagraph, secondParagraph, thirdParagraphTitle;

    Introduction();
};

#endif
