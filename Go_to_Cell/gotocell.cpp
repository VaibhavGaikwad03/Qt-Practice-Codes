#include "gotocell.h"
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>

GoToCellDialog::GoToCellDialog(QDialog *parent) : QDialog(parent)
{
    label = new QLabel;
    label->setText(tr("Cell Location"));
    line_edit = new QLineEdit;

    QHBoxLayout *upper_horizontal_layout = new QHBoxLayout;
    upper_horizontal_layout = new QHBoxLayout;
    upper_horizontal_layout->addWidget(label);
    upper_horizontal_layout->addWidget(line_edit);


    ok_button = new QPushButton("Ok");
    cancel_button = new QPushButton("Cancel");

    QHBoxLayout *lower_horizontal_layout = new QHBoxLayout;
    lower_horizontal_layout->addStretch();
    lower_horizontal_layout->addWidget(ok_button);
    lower_horizontal_layout->addWidget(cancel_button);

    QVBoxLayout *vertical_layout = new QVBoxLayout;
    vertical_layout->addLayout(upper_horizontal_layout);
    vertical_layout->addLayout(lower_horizontal_layout);

    connect(line_edit, SIGNAL(textChanged(QString)), this, SLOT(line_edit_text_changed()));

    setWindowTitle("Go to Cell");
    setLayout(vertical_layout);
}

void GoToCellDialog::line_edit_text_changed()
{
    ok_button->setEnabled(line_edit->hasAcceptableInput());
}
