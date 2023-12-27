#include "Data.hpp"

#include <QFile>
#include <QTextStream>
#include <cassert>

DefaultData::DefaultData() {
    QFile file("data/CalculationData.txt");
    assert(file.open(QIODevice::ReadOnly | QIODevice::Text));
    QTextStream in(&file);

    minutePerBurn = in.readLine().split(": ")[1].toDouble();
    kgTrashPerHour = in.readLine().split(": ")[1].toDouble();
    literLimeWaterPerUse = in.readLine().split(": ")[1].toDouble();
    hourOfLimeWaterUse = in.readLine().split(": ")[1].toInt();

    file.close();
}
