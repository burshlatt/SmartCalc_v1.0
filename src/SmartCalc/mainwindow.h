#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QApplication>
#include <QVector>
#include <QtMath>

#include <iostream>
#include <string>
#include <math.h>

extern "C" {
#include "../CFiles/calculator.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_num_0_clicked();
    void on_num_1_clicked();
    void on_num_2_clicked();
    void on_num_3_clicked();
    void on_num_4_clicked();
    void on_num_5_clicked();
    void on_num_6_clicked();
    void on_num_7_clicked();
    void on_num_8_clicked();
    void on_num_9_clicked();
    void on_addFunc_clicked();
    void on_subFunc_clicked();
    void on_mulFunc_clicked();
    void on_divFunc_clicked();
    void on_cosFunc_clicked();
    void on_sinFunc_clicked();
    void on_tanFunc_clicked();
    void on_sqrtFunc_clicked();
    void on_lnFunc_clicked();
    void on_logFunc_clicked();
    void on_acosFunc_clicked();
    void on_asinFunc_clicked();
    void on_atanFunc_clicked();
    void on_powFunc_clicked();
    void on_modFunc_clicked();
    void on_leftBracket_clicked();
    void on_rightBracket_clicked();
    void on_xSym_clicked();
    void on_dotSym_clicked();
    void on_delElem_clicked();
    void on_delAll_clicked();
    void on_resultFunc_clicked();
    void on_showGraph_clicked();

    void print_graph(double result);


private:
    Ui::MainWindow *ui;
    int is_x = 0;
    int graph_is_open = 0;
    int count_of_actions = 0;

    int N;
    double xBegin, xEnd, h, X;

    QVector<double> xCord, yCord;
};
#endif // MAINWINDOW_H
