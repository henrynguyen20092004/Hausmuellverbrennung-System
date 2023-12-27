#include "SpecificationSection.hpp"

SpecificationSection::SpecificationSection() {
    setObjectName("Thông số kỹ thuật");

    int numberOfRows = specification.data.size();

    titleLabel = new TextLabel(
        this, "Thông số kỹ thuật",
        "font-size: 28px; font-weight: bold; color: red;"
    );

    table =
        new Table(this, numberOfRows, 2, 920, CELL_HEIGHT * numberOfRows + 2);

    for (int i = 0; i < numberOfRows; ++i) {
        for (int j = 0; j < 2; ++j) {
            QTableWidgetItem *item =
                new QTableWidgetItem(specification.data[i][j]);
            item->setTextAlignment(Qt::AlignCenter);

            if (i == 0) {
                item->setBackground(QColor(0, 102, 204));
                item->setForeground(QColor(255, 255, 255));
                item->setFont(QFont("Times New Roman", 16, QFont::Bold));
            } else {
                item->setFont(QFont("Times New Roman", 12));
            }

            table->setItem(i, j, item);
        }
    }

    layout = new QVBoxLayout(this);
    layout->addWidget(titleLabel);
    layout->addWidget(table);
    layout->addSpacing(20);
}
