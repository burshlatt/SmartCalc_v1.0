#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QApplication>
#include <QVector>
#include <QtMath>
#include <QScreen>

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
    void on_subFunc_clicked();
    void on_dotSym_clicked();
    void on_delElem_clicked();
    void on_delAll_clicked();
    void on_resultFunc_clicked();
    void on_showGraph_clicked();
    void print_graph(double result);
    void symbols_clicked();
    void func_clicked();


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
