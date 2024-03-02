#include "finddialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QBoxLayout>
 
FindDialog::FindDialog(QWidget *parent) : QDialog(parent)
{
    label = new QLabel(tr("Find &what:"));
    line_edit = new QLineEdit;
    label->setBuddy(line_edit);

    case_checkbox = new QCheckBox(tr("Match &case"));
    backward_checkbox = new QCheckBox(tr("Search &backward"));

    find_button = new QPushButton(tr("&Find"));
    find_button->setDefault(true);
    find_button->setEnabled(false);

    close_button = new QPushButton(tr("Close"));

    connect(line_edit, SIGNAL(textChanged(QString)), this, SLOT(enable_find_button(QString)));
    connect(find_button, SIGNAL(clicked(bool)), this, SLOT(find_clicked()));
    connect(close_button, SIGNAL(clicked(bool)), this, SLOT(close()));

    QHBoxLayout *top_left_layout = new QHBoxLayout;
    top_left_layout->addWidget(label);
    top_left_layout->addWidget(line_edit);

    QVBoxLayout *left_layout = new QVBoxLayout;
    left_layout->addLayout(top_left_layout);
    left_layout->addWidget(case_checkbox);
    left_layout->addWidget(backward_checkbox);

    QVBoxLayout *right_layout = new QVBoxLayout;
    right_layout->addWidget(find_button);
    right_layout->addWidget(close_button);
    right_layout->addStretch();

    QHBoxLayout *main_layout = new QHBoxLayout;
    main_layout->addLayout(left_layout);
    main_layout->addLayout(right_layout);
    setLayout(main_layout);

    setWindowTitle(tr("Find or What?"));
    setFixedHeight(sizeHint().height());
}

void FindDialog::find_clicked()
{
    QString text = line_edit->text();
    Qt::CaseSensitivity cs = case_checkbox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;
    if (backward_checkbox->isChecked())
        emit find_prev(text, cs);
    else
        emit find_next(text, cs);
}


void FindDialog::enable_find_button(const QString &text)
{
    find_button->setEnabled(!text.isEmpty());
}
