#include "Specification.hpp"

#include <QFile>
#include <QTextStream>
#include <cassert>

Specification::Specification() {
    QFile file("data/Specification.txt");
    assert(file.open(QIODevice::ReadOnly | QIODevice::Text));
    QTextStream in(&file);

    while (!in.atEnd()) {
        data.push_back(in.readLine().split("|"));
    }

    file.close();
}
