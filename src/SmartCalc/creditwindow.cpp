#include "creditwindow.h"
#include "ui_creditwindow.h"

CreditWindow::CreditWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreditWindow)
{
    ui->setupUi(this);

    this->setFixedSize(480, 325);

//    QPieSeries *series = new QPieSeries();

//    series->append("Slice 1", 10);
//    series->append("Slice 2", 20);
//    series->append("Slice 3", 30);

//    QChartView *chartView = new QChartView();
//    chartView->setRenderHint(QPainter::Antialiasing);
//    chartView->setChart(series);

//    chartView->show();

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int x = (screenGeometry.width() - 480) / 2;
    int y = (screenGeometry.height() - 330) / 2;
    move(x, y);
}

CreditWindow::~CreditWindow()
{
    delete ui;
}

void CreditWindow::on_pushButton_clicked()
{
    this->setFixedSize(480, 480);
}

