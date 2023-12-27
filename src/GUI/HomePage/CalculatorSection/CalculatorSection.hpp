#ifndef CALCULATOR_SECTION_HPP
#define CALCULATOR_SECTION_HPP

#include <QBoxLayout>

#include "../../../API/Calculator/Calculator.hpp"
#include "../../Components/Button/Button.hpp"
#include "../../Components/LineEdit/LineEdit.hpp"

class CalculatorSection : public QWidget {
   public:
    CalculatorSection();

   private:
    Calculator calculator;

    TextLabel *titleLabel;
    LineEdit *use, *hour, *minute, *second, *kgTrash, *literLimeWater;
    Button *calculateButton;
    QHBoxLayout *timeLayout;
    QVBoxLayout *mainLayout;
    QWidget *lastEdited = nullptr;

    void connectLineEdits();
    void calculate();
};

#endif
