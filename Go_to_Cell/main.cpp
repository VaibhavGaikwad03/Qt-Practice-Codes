#include "gotocell.h"
#include <QApplication>
#include <QDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GoToCellDialog *gotocell = new GoToCellDialog;
    gotocell->show();
    return a.exec();
}
