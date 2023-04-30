#include "solar.h"
#include "insolation.h"
#include "month.h"
#include "discretize.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Solar w;
    w.show();
    return a.exec();
}





