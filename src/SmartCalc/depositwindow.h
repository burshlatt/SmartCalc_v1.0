#ifndef DEPOSITWINDOW_H
#define DEPOSITWINDOW_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QComboBox>
#include <QDateEdit>
#include <QLabel>

extern "C" {
#include "../CFiles/calculator.h"
}

namespace Ui {
class DepositWindow;
}

class DepositWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DepositWindow(QWidget *parent = nullptr);
    ~DepositWindow();

private slots:
    void on_calculator_clicked();
    void on_showResult_clicked();

signals:
    void firstWindow();

private:
    Ui::DepositWindow *ui;
};

#endif // DEPOSITWINDOW_H
