#ifndef CREDITWINDOW_H
#define CREDITWINDOW_H

#include <QDialog>
#include <QScreen>
#include <QApplication>

extern "C" {
#include "../CFiles/s21_calculator.h"
}

namespace Ui {
class CreditWindow;
}

class CreditWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CreditWindow(QWidget *parent = nullptr);
    ~CreditWindow();

private slots:
    void on_showResult_clicked();
    void on_calculator_clicked();

signals:
    void firstWindow();

private:
    Ui::CreditWindow *ui;
};

#endif // CREDITWINDOW_H
