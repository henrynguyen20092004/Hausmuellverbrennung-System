#ifndef HOME_PAGE_HPP
#define HOME_PAGE_HPP

#include <QStackedWidget>

#include "CalculatorSection/CalculatorSection.hpp"
#include "HeaderBar/HeaderBar.hpp"
#include "IntroductionSection/IntroductionSection.hpp"
#include "SpecificationSection/SpecificationSection.hpp"
#include "SwitchSectionButton/SwitchSectionButton.hpp"

class HomePage : public QWidget {
   public:
    HomePage();

   private:
    HeaderBar *headerBar;
    IntroductionSection *introductionSection;
    SpecificationSection *specificationSection;
    CalculatorSection *calculatorSection;
    QStackedWidget *stackedWidget;
    SwitchSectionButton *switchSectionButton;
};

#endif
