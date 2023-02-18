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
#include "../CFiles/s21_calculator.h"
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
    void on_addWaste_clicked();
    void on_calculator_clicked();
    void on_showResult_clicked();
    void on_addPayment_clicked();
    void on_deleteWaste_clicked();
    void on_deletePayment_clicked();
    void check_period(int converted_time, double *add_sum, double *waste_sum);

signals:
    void firstWindow();

private:
    Ui::DepositWindow *ui;

    int count_of_elem_add = 0;
    int count_of_elem_waste = 0;

    QVBoxLayout *addVbox;
    QVBoxLayout* wasteVbox;

    QVector<QComboBox*> comboBoxesAdd;
    QVector<QDateEdit*> dateEditsAdd;
    QVector<QLineEdit*> lineEditsAdd;

    QVector<QComboBox*> comboBoxesWaste;
    QVector<QDateEdit*> dateEditsWaste;
    QVector<QLineEdit*> lineEditsWaste;
};

#endif // DEPOSITWINDOW_H
