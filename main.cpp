#include <QApplication>

#include "src/GUI/HomePage/HomePage.hpp"

int main(int argc, char **argv) {
    srand(time(NULL));
    QApplication app(argc, argv);
    HomePage homePage;
    return app.exec();
}
