#include "depositwindow.h"
#include "ui_depositwindow.h"

DepositWindow::DepositWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DepositWindow)
{
    ui->setupUi(this);

    this->setFixedSize(1000, 425);

    ui->periodCombo->addItem("Каждый день");
    ui->periodCombo->addItem("Каждую неделю");
    ui->periodCombo->addItem("Раз в месяц");
    ui->periodCombo->addItem("Раз в квартал");
    ui->periodCombo->addItem("Раз в полгода");
    ui->periodCombo->addItem("Раз в год");
    ui->periodCombo->addItem("В конце срока");

    QScrollArea* scrollPayment = new QScrollArea(ui->addLayout->parentWidget());
    QVBoxLayout* addVbox = new QVBoxLayout();
    scrollPayment->setWidgetResizable(true);
    scrollPayment->setWidget(new QWidget(scrollPayment));
    scrollPayment->widget()->setLayout(addVbox);
    ui->addLayout->addWidget(scrollPayment);

    QObject::connect(ui->addPayment, &QPushButton::clicked, [=]() {
        QHBoxLayout* hboxLayout = new QHBoxLayout();
        QComboBox* addComboBox = new QComboBox(scrollPayment->widget());
        addComboBox->addItems({"Разовое", "Раз в месяц", "Раз в 2 месяца", "Раз в квартал", "Раз в полгода", "Раз в год"});
        addComboBox->setFixedWidth(110);
        addComboBox->setFixedHeight(35);
        hboxLayout->addWidget(addComboBox);
        QDateEdit* addData = new QDateEdit(scrollPayment->widget());
        addData->setCalendarPopup(true);
        addData->setFixedWidth(105);
        addData->setFixedHeight(35);
        hboxLayout->addWidget(addData);
        QLineEdit* addLine = new QLineEdit(scrollPayment->widget());
        addLine->setFixedWidth(200);
        addLine->setFixedHeight(35);
        hboxLayout->addWidget(addLine);
        addVbox->addLayout(hboxLayout);
    });

    QObject::connect(ui->deletePayment, &QPushButton::clicked, [=]() {
        int count = addVbox->count();
        if (count > 1) {
            QLayout* layout = addVbox->itemAt(count - 2)->layout();
            if (layout != nullptr) {
                QWidget* widget1 = layout->itemAt(0)->widget();
                QWidget* widget2 = layout->itemAt(1)->widget();
                QWidget* widget3 = layout->itemAt(2)->widget();
                delete layout;
                delete widget1;
                delete widget2;
                delete widget3;
            }
        }
    });

    QScrollArea* scrollWaste = new QScrollArea(ui->wasteLayout->parentWidget());
    QVBoxLayout* wasteVbox = new QVBoxLayout();
    scrollWaste->setWidgetResizable(true);
    scrollWaste->setWidget(new QWidget(scrollWaste));
    scrollWaste->widget()->setLayout(wasteVbox);
    ui->wasteLayout->addWidget(scrollWaste);

    QObject::connect(ui->addWaste, &QPushButton::clicked, [=]() {
        QHBoxLayout* hboxLayout = new QHBoxLayout();
        QComboBox* addComboBox = new QComboBox(scrollWaste->widget());
        addComboBox->addItems({"Разовое", "Раз в месяц", "Раз в 2 месяца", "Раз в квартал", "Раз в полгода", "Раз в год"});
        addComboBox->setFixedWidth(110);
        addComboBox->setFixedHeight(35);
        hboxLayout->addWidget(addComboBox);
        QDateEdit* addData = new QDateEdit(scrollWaste->widget());
        addData->setCalendarPopup(true);
        addData->setFixedWidth(105);
        addData->setFixedHeight(35);
        hboxLayout->addWidget(addData);
        QLineEdit* addLine = new QLineEdit(scrollWaste->widget());
        addLine->setFixedWidth(200);
        addLine->setFixedHeight(35);
        hboxLayout->addWidget(addLine);
        wasteVbox->addLayout(hboxLayout);
    });

    QObject::connect(ui->deleteWaste, &QPushButton::clicked, [=]() {
        int count = wasteVbox->count();
        if (count > 1) {
            QLayout* layout = wasteVbox->itemAt(count - 2)->layout();
            if (layout != nullptr) {
                QWidget* widget1 = layout->itemAt(0)->widget();
                QWidget* widget2 = layout->itemAt(1)->widget();
                QWidget* widget3 = layout->itemAt(2)->widget();
                delete layout;
                delete widget1;
                delete widget2;
                delete widget3;
            }
        }
    });
}

DepositWindow::~DepositWindow() {
    delete ui;
}

void DepositWindow::on_calculator_clicked() {
    this->close();
    emit firstWindow();
}

void DepositWindow::on_showResult_clicked() {
    this->setFixedSize(1000, 520);
    ui->tax->clear();
    ui->resultSum->clear();
    ui->resultProfit->clear();
    ui->resultPercent->clear();
    int time_type = 0;
    int period_type = 0;
    int capitalization = 0;
    double sum_result = 0.0;
    double tax_result = 0.0;
    double profit_result = 0.0;
    double percent_result = 0.0;
    int time = ui->time->text().toInt();
    double percent = ui->percent->text().toDouble();
    double tax_rate = ui->taxRate->text().toDouble();
    double sum = ui->depositAmount->text().toDouble();
    if (ui->yes->isChecked()) {
        capitalization = 1;
    }
    if (ui->day->isChecked()) {
        time_type = 1;
    } else if (ui->month->isChecked()) {
        time_type = 2;
    } else if (ui->year->isChecked()) {
        time_type = 3;
    }
    if (ui->periodCombo->currentText() == "Каждый день") {
        period_type = 1;
    } else if (ui->periodCombo->currentText() == "Каждую неделю") {
        period_type = 2;
    } else if (ui->periodCombo->currentText() == "Раз в месяц") {
        period_type = 3;
    } else if (ui->periodCombo->currentText() == "Раз в квартал") {
        period_type = 4;
    } else if (ui->periodCombo->currentText() == "Раз в полгода") {
        period_type = 5;
    } else if (ui->periodCombo->currentText() == "Раз в год") {
        period_type = 6;
    } else if (ui->periodCombo->currentText() == "В конце срока") {
        period_type = 7;
    }
    deposit_calculator(sum, time, time_type, percent, tax_rate, period_type, capitalization, &percent_result, &tax_result, &profit_result, &sum_result);
    ui->tax->setText(ui->resultPercent->text() + QString::number(tax_result, 'f', 2));
    ui->resultSum->setText(ui->resultPercent->text() + QString::number(sum_result, 'f', 2));
    ui->resultProfit->setText(ui->resultPercent->text() + QString::number(profit_result, 'f', 2));
    ui->resultPercent->setText(ui->resultPercent->text() + QString::number(percent_result, 'f', 2));
}
