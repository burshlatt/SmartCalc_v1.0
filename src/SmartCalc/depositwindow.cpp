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
    this->setFixedSize(1000, 570);
//    double sum = ui->depositAmount->text().toDouble();
//    int time = ui->time->text().toInt();
//    double percent = ui->percent->text().toDouble();
//    double tax_rate = ui->taxRate->text().toDouble();
//    if (ui->periodCombo->currentText() == "Каждый день") {

//    }
}
