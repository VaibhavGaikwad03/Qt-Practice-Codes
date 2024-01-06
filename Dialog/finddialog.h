#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
class QWidget;
class QLineEdit;
class QPushButton;
class QCheckBox;
class QLabel;

class FindDialog : public QDialog
{
    Q_OBJECT;

public:
    FindDialog(QWidget *parent = 0);

private:
    QLabel *label;
    QLineEdit * line_edit;
    QPushButton *find_button;
    QPushButton *close_button;
    QCheckBox *case_checkbox;
    QCheckBox *backward_checkbox;

signals:
    void find_next(const QString &str, Qt::CaseSensitivity cs);
    void find_prev(const QString &str, Qt::CaseSensitivity cs);

private slots:
    void find_clicked();
    void enable_find_button(const QString &text);
};

#endif // FINDDIALOG_H
