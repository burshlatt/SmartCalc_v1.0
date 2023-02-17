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

    addVbox = new QVBoxLayout();
    ui->scrollPayment->widget()->setLayout(addVbox);
    ui->addLayout->addWidget(ui->scrollPayment);

    wasteVbox = new QVBoxLayout();
    ui->scrollWaste->widget()->setLayout(wasteVbox);
    ui->wasteLayout->addWidget(ui->scrollWaste);
}

DepositWindow::~DepositWindow() {
    delete ui;
}

void DepositWindow::on_calculator_clicked() {
    this->close();
    emit firstWindow();
}

void DepositWindow::on_addPayment_clicked() {
    QHBoxLayout* hboxLayout = new QHBoxLayout();
    QComboBox* addComboBox = new QComboBox(ui->scrollPayment->widget());
    addComboBox->addItem("Разовое");
    addComboBox->addItem("Раз в месяц");
    addComboBox->addItem("Раз в 2 месяца");
    addComboBox->addItem("Раз в квартал");
    addComboBox->addItem("Раз в полгода");
    addComboBox->addItem("Раз в год");
    addComboBox->setFixedWidth(110);
    addComboBox->setFixedHeight(35);
    hboxLayout->addWidget(addComboBox);
    QDateEdit* addData = new QDateEdit(ui->scrollPayment->widget());
    addData->setCalendarPopup(true);
    addData->setFixedWidth(105);
    addData->setFixedHeight(35);
    hboxLayout->addWidget(addData);
    QLineEdit* addLine = new QLineEdit(ui->scrollPayment->widget());
    addLine->setFixedWidth(200);
    addLine->setFixedHeight(35);
    hboxLayout->addWidget(addLine);

    addVbox->addLayout(hboxLayout);

    comboBoxesAdd.append(addComboBox);
    dateEditsAdd.append(addData);
    lineEditsAdd.append(addLine);
    count_of_elem_add++;
}

void DepositWindow::on_deletePayment_clicked() {
    if (count_of_elem_add > 0) {
        QLayout* layout = addVbox->itemAt(count_of_elem_add - 1)->layout();
        QWidget* widget1 = layout->itemAt(0)->widget();
        QWidget* widget2 = layout->itemAt(1)->widget();
        QWidget* widget3 = layout->itemAt(2)->widget();
        delete layout;
        delete widget1;
        delete widget2;
        delete widget3;
        comboBoxesAdd.removeLast();
        dateEditsAdd.removeLast();
        lineEditsAdd.removeLast();
        count_of_elem_add--;
    }
}

void DepositWindow::on_addWaste_clicked() {
    QHBoxLayout* hboxLayout = new QHBoxLayout();
    QComboBox* delComboBox = new QComboBox(ui->scrollWaste->widget());
    delComboBox->addItem("Разовое");
    delComboBox->addItem("Раз в месяц");
    delComboBox->addItem("Раз в 2 месяца");
    delComboBox->addItem("Раз в квартал");
    delComboBox->addItem("Раз в полгода");
    delComboBox->addItem("Раз в год");
    delComboBox->setFixedWidth(110);
    delComboBox->setFixedHeight(35);
    hboxLayout->addWidget(delComboBox);
    QDateEdit* delData = new QDateEdit(ui->scrollWaste->widget());
    delData->setCalendarPopup(true);
    delData->setFixedWidth(105);
    delData->setFixedHeight(35);
    hboxLayout->addWidget(delData);
    QLineEdit* delLine = new QLineEdit(ui->scrollWaste->widget());
    delLine->setFixedWidth(200);
    delLine->setFixedHeight(35);
    hboxLayout->addWidget(delLine);

    wasteVbox->addLayout(hboxLayout);

    comboBoxesWaste.append(delComboBox);
    dateEditsWaste.append(delData);
    lineEditsWaste.append(delLine);
    count_of_elem_waste++;
}

void DepositWindow::on_deleteWaste_clicked() {
    if (count_of_elem_waste > 0) {
        QLayout* layout = wasteVbox->itemAt(count_of_elem_waste - 1)->layout();
        QWidget* widget1 = layout->itemAt(0)->widget();
        QWidget* widget2 = layout->itemAt(1)->widget();
        QWidget* widget3 = layout->itemAt(2)->widget();
        delete layout;
        delete widget1;
        delete widget2;
        delete widget3;
        comboBoxesWaste.removeLast();
        dateEditsWaste.removeLast();
        lineEditsWaste.removeLast();
        count_of_elem_waste--;
    }
}

void DepositWindow::check_period(int converted_time, double *add_sum, double *waste_sum) {
    if (comboBoxesAdd.size() > 0 && dateEditsAdd.size() > 0 && lineEditsAdd.size() > 0) {
        for (int i = 0; i < count_of_elem_add; i++) {
//            QDate date_add = dateEditsAdd[i]->date();
            QString text_add = lineEditsAdd[i]->text();
            QString combobox_add = comboBoxesAdd[i]->currentText();
            if (combobox_add == "Разовое") {
                *add_sum += text_add.toDouble();
            } else if (combobox_add == "Раз в месяц") {
                *add_sum += add_start_sum(text_add.toDouble(), converted_time, 1);
            } else if (combobox_add == "Раз в 2 месяца") {
                *add_sum += add_start_sum(text_add.toDouble(), converted_time, 2);
            } else if (combobox_add == "Раз в квартал") {
                *add_sum += add_start_sum(text_add.toDouble(), converted_time, 3);
            } else if (combobox_add == "Раз в полгода") {
                *add_sum += add_start_sum(text_add.toDouble(), converted_time, 4);
            } else if (combobox_add == "Раз в год") {
                *add_sum += add_start_sum(text_add.toDouble(), converted_time, 5);
            }
        }
    }
    if (comboBoxesWaste.size() > 0 && dateEditsWaste.size() > 0 && lineEditsWaste.size() > 0) {
        for (int i = 0; i < count_of_elem_waste; i++) {
//            QDate date_waste = dateEditsWaste[i]->date();
            QString text_waste = lineEditsWaste[i]->text();
            QString combobox_waste = comboBoxesWaste[i]->currentText();
            if (combobox_waste == "Разовое") {
                *waste_sum += text_waste.toDouble();
            } else if (combobox_waste == "Раз в месяц") {
                *waste_sum += add_start_sum(text_waste.toDouble(), converted_time, 1);
            } else if (combobox_waste == "Раз в 2 месяца") {
                *waste_sum += add_start_sum(text_waste.toDouble(), converted_time, 2);
            } else if (combobox_waste == "Раз в квартал") {
                *waste_sum += add_start_sum(text_waste.toDouble(), converted_time, 3);
            } else if (combobox_waste == "Раз в полгода") {
                *waste_sum += add_start_sum(text_waste.toDouble(), converted_time, 4);
            } else if (combobox_waste == "Раз в год") {
                *waste_sum += add_start_sum(text_waste.toDouble(), converted_time, 5);
            }
        }
    }
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
    int time = ui->time->text().toInt();

    double add_sum = 0.0;
    double waste_sum = 0.0;
    double sum_result = 0.0;
    double tax_result = 0.0;
    double profit_result = 0.0;
    double percent_result = 0.0;
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

    int converted_time = convert_to_months(time, time_type);

    check_period(converted_time, &add_sum, &waste_sum);
    deposit_calculator(sum + add_sum - waste_sum, time, time_type, percent, tax_rate, period_type, capitalization, &percent_result, &tax_result, &profit_result, &sum_result);

    ui->tax->setText(ui->resultPercent->text() + QString::number(tax_result, 'f', 2));
    ui->resultSum->setText(ui->resultPercent->text() + QString::number(sum_result, 'f', 2));
    ui->resultProfit->setText(ui->resultPercent->text() + QString::number(profit_result, 'f', 2));
    ui->resultPercent->setText(ui->resultPercent->text() + QString::number(percent_result, 'f', 2));
}
