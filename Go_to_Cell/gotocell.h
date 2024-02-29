#ifndef GOTOCELL_H
#define GOTOCELL_H
 
#include <QDialog>

class QLabel;
class QLineEdit;
class QPushButton;
class QHBoxLayout;

class GoToCellDialog : public QDialog
{
    QLabel *label;
    QLineEdit *line_edit;
    QPushButton *ok_button;
    QPushButton *cancel_button;

public:
    GoToCellDialog(QDialog *parent = 0);
private slots:
    void line_edit_text_changed();
};

#endif // GOTOCELL_H
