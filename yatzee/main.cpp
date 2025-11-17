#include "yatzee.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Yatzee w;
    w.show();
    return a.exec();
}
