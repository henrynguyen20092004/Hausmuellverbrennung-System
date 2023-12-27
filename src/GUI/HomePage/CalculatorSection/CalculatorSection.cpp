#include "CalculatorSection.hpp"

#include <QRegularExpression>
#include <cmath>

#define DEFAULT_TEXT "0"
#define DECIMAL_POINT 2

QString toString(double num) {
    QString str = QString::number(num, 'f', DECIMAL_POINT);
    str.remove(QRegularExpression("\\.?0+$"));
    return str;
}

CalculatorSection::CalculatorSection() {
    setObjectName("Máy tính");

    titleLabel = new TextLabel(
        this, "Máy tính", "font-size: 28px; font-weight: bold; color: red;"
    );

    use = new LineEdit(this, "Số lần đốt");
    hour = new LineEdit(this, "Số giờ (h)");
    minute = new LineEdit(this, "Số phút (m)");
    second = new LineEdit(this, "Số giây (s)");
    kgTrash = new LineEdit(this, "Khối lượng rác (kg)");
    literLimeWater = new LineEdit(this, "Lượng nước vôi (l)", true);
    connectLineEdits();

    calculateButton = new Button(this, "Tính toán", "font-size: 20px;");
    connect(calculateButton, CLICKED, this, &CalculatorSection::calculate);

    timeLayout = new QHBoxLayout;
    timeLayout->addWidget(hour);
    timeLayout->addWidget(minute);
    timeLayout->addWidget(second);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(use);
    mainLayout->addLayout(timeLayout);
    mainLayout->addWidget(kgTrash);
    mainLayout->addWidget(literLimeWater);
    mainLayout->addWidget(calculateButton);
    mainLayout->addSpacing(200);
}

void CalculatorSection::connectLineEdits() {
    use->connectTextEditedSignal([=]() {
        hour->setDefaultText();
        minute->setDefaultText();
        second->setDefaultText();
        kgTrash->setDefaultText();
        literLimeWater->setDefaultText();
        lastEdited = use;
    });
    use->connectReturnPressedSignal([=]() { calculate(); });

    hour->connectTextEditedSignal([=]() {
        use->setDefaultText();
        kgTrash->setDefaultText();
        literLimeWater->setDefaultText();
        lastEdited = hour;
    });
    hour->connectReturnPressedSignal([=]() { calculate(); });

    minute->connectTextEditedSignal([=]() {
        use->setDefaultText();
        kgTrash->setDefaultText();
        literLimeWater->setDefaultText();
        lastEdited = minute;
    });
    minute->connectReturnPressedSignal([=]() { calculate(); });

    second->connectTextEditedSignal([=]() {
        use->setDefaultText();
        kgTrash->setDefaultText();
        literLimeWater->setDefaultText();
        lastEdited = second;
    });
    second->connectReturnPressedSignal([=]() { calculate(); });

    kgTrash->connectTextEditedSignal([=]() {
        use->setDefaultText();
        hour->setDefaultText();
        minute->setDefaultText();
        second->setDefaultText();
        literLimeWater->setDefaultText();
        lastEdited = kgTrash;
    });
    kgTrash->connectReturnPressedSignal([=]() { calculate(); });
}

void CalculatorSection::calculate() {
    Data data;

    if (lastEdited == use) {
        data =
            calculator.calculate(int(std::ceil(use->getText().toDouble() * 2)));
    } else if (lastEdited == hour || lastEdited == minute || lastEdited == second) {
        data = calculator.calculate(
            hour->getText().toInt(), minute->getText().toInt(),
            second->getText().toDouble()
        );
    } else if (lastEdited == kgTrash) {
        data = calculator.calculate(kgTrash->getText().toDouble());
    }

    use->setText(toString(data.use / 2.0));
    hour->setText(QString::number(data.hour));
    minute->setText(QString::number(data.minute));
    second->setText(toString(data.second));
    kgTrash->setText(toString(data.kgTrash));
    literLimeWater->setText(QString::number(data.literLimeWater));
}
