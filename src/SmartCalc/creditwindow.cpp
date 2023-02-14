#include "creditwindow.h"
#include "ui_creditwindow.h"
//#include "mainwindow.h"

CreditWindow::CreditWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreditWindow)
{
    ui->setupUi(this);

    this->setFixedSize(480, 325);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int x = (screenGeometry.width() - 480) / 2;
    int y = (screenGeometry.height() - 330) / 2;
    move(x, y);
}

CreditWindow::~CreditWindow() {
    delete ui;
}

void CreditWindow::on_calculator_clicked() {
    this->close();
    emit firstWindow();
}

void CreditWindow::on_showResult_clicked() {
    this->setFixedSize(480, 480);
}
