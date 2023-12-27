#include "Calculator.hpp"

#include <cmath>

#define PRECISION 0.01

Data Calculator::calculate(double kgTrash) const {
    Data data;

    if (kgTrash < 0.0) {
        return data;
    }

    double hour = kgTrash / defaultData.kgTrashPerHour;
    data.hour = hour;

    double minute = (hour - data.hour) * 60.0;
    data.minute = minute;

    data.second = (minute - data.minute) * 60.0;

    if (60.0 - data.second < PRECISION) {
        data.second = 0.0;
        data.minute += 1.0;
    }

    if (60.0 - data.minute < PRECISION) {
        data.minute = 0.0;
        data.hour += 1.0;
    }

    data.kgTrash = kgTrash;
    data.literLimeWater = defaultData.literLimeWaterPerUse *
                          std::ceil(hour / defaultData.hourOfLimeWaterUse);
    data.use =
        std::ceil((data.hour * 60.0 + minute) / defaultData.minutePerBurn * 2);

    return data;
}

Data Calculator::calculate(int use) const {
    Data data;

    if (use < 0) {
        return data;
    }

    double minute = use * defaultData.minutePerBurn / 2;

    data.use = use;
    data.hour = minute / 60.0;
    data.minute = minute - data.hour * 60.0;
    data.second = (minute - data.hour * 60.0 - data.minute) * 60.0;
    data.kgTrash = minute * defaultData.kgTrashPerHour / 60.0;
    data.literLimeWater =
        defaultData.literLimeWaterPerUse *
        std::ceil(minute / 60.0 / defaultData.hourOfLimeWaterUse);

    return data;
}

Data Calculator::calculate(int hour, int minute, double second) const {
    Data data;

    if (hour < 0 || minute < 0 || second < 0.0) {
        return data;
    }

    double totalHour = hour + minute / 60.0 + second / 3600;

    data.use = std::ceil(totalHour / defaultData.minutePerBurn * 120);
    data.hour = hour;
    data.minute = minute;
    data.second = second;
    data.kgTrash = totalHour * defaultData.kgTrashPerHour;
    data.literLimeWater = defaultData.literLimeWaterPerUse *
                          std::ceil(totalHour / defaultData.hourOfLimeWaterUse);

    return data;
}
