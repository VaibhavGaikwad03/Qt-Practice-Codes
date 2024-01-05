#include "mainwindow.h"

#include <QApplication>
#include <QToolBox>
#include <QWidget>
#include <QBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *main_win = new QWidget;

    QToolBox *toolBox = new QToolBox(main_win);
    QWidget *page1 = new QWidget();
    // Add widgets to page1

    QWidget *page2 = new QWidget();
    // Add widgets to page2

    toolBox->addItem(page1, "Page 1");
    toolBox->addItem(page2, "Page 2");

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(toolBox);
    main_win->setLayout(layout);
    main_win->show();
    return a.exec();
}
