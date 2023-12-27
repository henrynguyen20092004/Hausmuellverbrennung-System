#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <QString>

#include "Data/Data.hpp"

class Calculator {
   public:
    Data calculate(double kgTrash) const;
    Data calculate(int use) const;
    Data calculate(int hour, int minute, double second) const;

   private:
    DefaultData defaultData;
};

#endif
