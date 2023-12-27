#include "Introduction.hpp"

#include <QFile>
#include <QTextStream>
#include <cassert>

Introduction::Introduction() {
    QFile file("data/Introduction.txt");
    assert(file.open(QIODevice::ReadOnly | QIODevice::Text));
    QTextStream in(&file);

    firstParagraph = in.readLine();
    secondParagraph = in.readLine();
    thirdParagraphTitle = in.readLine();

    while (!in.atEnd()) {
        reasons.append(in.readLine());
    }

    file.close();
}
