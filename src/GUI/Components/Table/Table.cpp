#include "Table.hpp"

#include <QHeaderView>

Table::Table(QWidget *parent, int row, int column, int width, int height)
    : QTableWidget(row, column, parent) {
    setFixedHeight(height);
    setStyleSheet("background: white; border: 1px solid;");
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    setFocusPolicy(Qt::NoFocus);
    setSelectionMode(QAbstractItemView::NoSelection);

    verticalHeader()->setVisible(false);
    horizontalHeader()->setVisible(false);

    for (int i = 0; i < column; ++i) {
        setColumnWidth(i, (width - 20) / column);
    }

    for (int i = 0; i < row; ++i) {
        setRowHeight(i, CELL_HEIGHT);
    }
}
