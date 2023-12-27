#ifndef TABLE_HPP
#define TABLE_HPP

#include <QTableWidget>

#define CELL_HEIGHT 40

class Table : public QTableWidget {
   public:
    Table(QWidget *parent, int row, int column, int width, int height);
};

#endif
