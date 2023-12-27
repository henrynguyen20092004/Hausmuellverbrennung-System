#include "HomePage.hpp"

#include <QStackedWidget>

HomePage::HomePage() {
    setFixedSize(1280, 720);
    setStyleSheet("font-family: Times New Roman;");

    headerBar = new HeaderBar(this, "Hausmüllverbrennung System");
    introductionSection = new IntroductionSection;
    specificationSection = new SpecificationSection;
    calculatorSection = new CalculatorSection;

    stackedWidget = new QStackedWidget(this);
    stackedWidget->setGeometry(
        180, HEADER_BAR_HEIGHT, 920, 720 - HEADER_BAR_HEIGHT
    );
    stackedWidget->addWidget(introductionSection);
    stackedWidget->addWidget(specificationSection);
    stackedWidget->addWidget(calculatorSection);
    stackedWidget->setCurrentIndex(0);

    switchSectionButton = new SwitchSectionButton(this, stackedWidget);

    show();
}
