#include "creditwindow.h"
#include "ui_creditwindow.h"

CreditWindow::CreditWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreditWindow)
{
    ui->setupUi(this);

    this->setFixedSize(480, 325);

//    QPixmap bkgnd("../../../../pictures/2.png");
//    QPalette palette;
//    palette.setBrush(QPalette::Window, bkgnd);
//    this->setPalette(palette);

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
    ui->monthRes->clear();
    ui->overPay->clear();
    ui->resultSum->clear();
    double all_sum = 0.0;
    double over_pay = 0.0;
    double month_payment = 0.0;
    double last_payment = 0.0;
    double first_payment = 0.0;
    int termCred = ui->creditTerm->text().toInt();
    double sumCred = ui->creditSum->text().toDouble();
    double percentCred = ui->percent->text().toDouble();
    ui->monthRes->setText(ui->monthRes->text() + "0");
    if (ui->annu->isChecked()) {
        if (ui->month->isChecked()) {
            all_sum = annuity_credit(sumCred, termCred, 1, percentCred, &month_payment, &over_pay);
        }
        if (ui->year->isChecked()) {
            all_sum = annuity_credit(sumCred, termCred, 2, percentCred, &month_payment, &over_pay);
        }
        ui->monthRes->clear();
        ui->monthRes->setText(ui->monthRes->text() + QString::number(month_payment));
    }
    if (ui->differ->isChecked()) {
        if (ui->month->isChecked()) {
            all_sum = differentiated_credit(sumCred, termCred, 1, percentCred, &first_payment, &last_payment, &over_pay);
        }
        if (ui->year->isChecked()) {
            all_sum = differentiated_credit(sumCred, termCred, 2, percentCred, &first_payment, &last_payment, &over_pay);
        }
        ui->monthRes->clear();
        ui->monthRes->setText(ui->monthRes->text() + QString::number(first_payment) + " ... " + QString::number(last_payment));
    }
    ui->overPay->setText(ui->overPay->text() + QString::number(over_pay));
    ui->resultSum->setText(ui->resultSum->text() + QString::number(all_sum));
}
