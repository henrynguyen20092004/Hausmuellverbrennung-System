#ifndef DATA_HPP
#define DATA_HPP

#include <QTime>

struct Data {
    double second = 0, kgTrash = 0;
    int hour = 0, minute = 0, use = 0, literLimeWater = 0;
};

struct DefaultData {
    double kgTrashPerHour, literLimeWaterPerUse, minutePerBurn;
    int hourOfLimeWaterUse;

    DefaultData();
};

#endif
