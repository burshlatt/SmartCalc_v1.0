/********************************************************************************
** Form generated from reading UI file 'depositwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPOSITWINDOW_H
#define UI_DEPOSITWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DepositWindow
{
public:
    QPushButton *calculator;
    QPushButton *creditCalc;
    QPushButton *showResult;
    QLineEdit *tax;
    QLabel *label_12;
    QLineEdit *time;
    QLabel *label;
    QLabel *label_6;
    QLineEdit *percent;
    QLabel *label_8;
    QLineEdit *resultProfit;
    QLabel *label_10;
    QLineEdit *depositAmount;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QRadioButton *day;
    QRadioButton *month;
    QRadioButton *year;
    QLabel *label_3;
    QLabel *label_11;
    QLabel *label_9;
    QLabel *label_7;
    QLineEdit *resultPercent;
    QLabel *label_2;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *yes;
    QRadioButton *no;
    QLabel *label_13;
    QLineEdit *taxRate;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *resultSum;
    QLabel *label_17;
    QLabel *label_18;
    QPushButton *addPayment;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *addLayout;
    QScrollArea *scrollPayment;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_19;
    QPushButton *deletePayment;
    QPushButton *deleteWaste;
    QPushButton *addWaste;
    QLabel *label_20;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *wasteLayout;
    QScrollArea *scrollWaste;
    QWidget *scrollAreaWidgetContents_2;
    QComboBox *periodCombo;

    void setupUi(QDialog *DepositWindow)
    {
        if (DepositWindow->objectName().isEmpty())
            DepositWindow->setObjectName("DepositWindow");
        DepositWindow->resize(1000, 520);
        DepositWindow->setMinimumSize(QSize(1000, 520));
        DepositWindow->setMaximumSize(QSize(1000, 520));
        DepositWindow->setStyleSheet(QString::fromUtf8("QDialog {\n"
"	background-color: rgb(255, 219, 139);\n"
"}"));
        calculator = new QPushButton(DepositWindow);
        calculator->setObjectName("calculator");
        calculator->setGeometry(QRect(0, 0, 500, 20));
        calculator->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 160, 122);\n"
"  color: black; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        creditCalc = new QPushButton(DepositWindow);
        creditCalc->setObjectName("creditCalc");
        creditCalc->setGeometry(QRect(500, 0, 500, 20));
        creditCalc->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 160, 122);\n"
"  color: black; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        showResult = new QPushButton(DepositWindow);
        showResult->setObjectName("showResult");
        showResult->setGeometry(QRect(170, 360, 130, 40));
        showResult->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 160, 122);\n"
"  color: black; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        tax = new QLineEdit(DepositWindow);
        tax->setObjectName("tax");
        tax->setGeometry(QRect(220, 480, 200, 35));
        QFont font;
        font.setPointSize(17);
        tax->setFont(font);
        tax->setReadOnly(true);
        label_12 = new QLabel(DepositWindow);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(960, 430, 40, 35));
        QFont font1;
        font1.setPointSize(16);
        label_12->setFont(font1);
        label_12->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        time = new QLineEdit(DepositWindow);
        time->setObjectName("time");
        time->setGeometry(QRect(175, 80, 130, 35));
        time->setFont(font);
        label = new QLabel(DepositWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(5, 30, 165, 35));
        QFont font2;
        font2.setPointSize(15);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        label_6 = new QLabel(DepositWindow);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 430, 185, 35));
        label_6->setFont(font2);
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        percent = new QLineEdit(DepositWindow);
        percent->setObjectName("percent");
        percent->setGeometry(QRect(175, 130, 130, 35));
        percent->setFont(font);
        label_8 = new QLabel(DepositWindow);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(310, 130, 170, 35));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        resultProfit = new QLineEdit(DepositWindow);
        resultProfit->setObjectName("resultProfit");
        resultProfit->setGeometry(QRect(715, 430, 240, 35));
        resultProfit->setFont(font);
        resultProfit->setReadOnly(true);
        label_10 = new QLabel(DepositWindow);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(425, 430, 40, 35));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        depositAmount = new QLineEdit(DepositWindow);
        depositAmount->setObjectName("depositAmount");
        depositAmount->setGeometry(QRect(175, 30, 130, 35));
        depositAmount->setFont(font);
        label_4 = new QLabel(DepositWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(5, 293, 205, 35));
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        label_5 = new QLabel(DepositWindow);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(520, 430, 191, 35));
        label_5->setFont(font2);
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        layoutWidget_2 = new QWidget(DepositWindow);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(310, 80, 196, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        day = new QRadioButton(layoutWidget_2);
        day->setObjectName("day");
        QFont font3;
        font3.setPointSize(14);
        day->setFont(font3);
        day->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	background-color: rgb(59, 60, 54);\n"
"	color: white;\n"
"}"));

        horizontalLayout->addWidget(day);

        month = new QRadioButton(layoutWidget_2);
        month->setObjectName("month");
        month->setFont(font3);
        month->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	background-color: rgb(59, 60, 54);\n"
"	color: white;\n"
"}"));

        horizontalLayout->addWidget(month);

        year = new QRadioButton(layoutWidget_2);
        year->setObjectName("year");
        year->setFont(font3);
        year->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	background-color: rgb(59, 60, 54);\n"
"	color: white;\n"
"}"));

        horizontalLayout->addWidget(year);

        label_3 = new QLabel(DepositWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(5, 130, 165, 35));
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        label_11 = new QLabel(DepositWindow);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(425, 480, 40, 35));
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        label_9 = new QLabel(DepositWindow);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(310, 30, 170, 35));
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        label_7 = new QLabel(DepositWindow);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 480, 185, 35));
        label_7->setFont(font2);
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        resultPercent = new QLineEdit(DepositWindow);
        resultPercent->setObjectName("resultPercent");
        resultPercent->setGeometry(QRect(220, 430, 200, 35));
        resultPercent->setFont(font);
        resultPercent->setReadOnly(true);
        label_2 = new QLabel(DepositWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(5, 80, 165, 35));
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        layoutWidget_3 = new QWidget(DepositWindow);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(200, 290, 104, 41));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        yes = new QRadioButton(layoutWidget_3);
        yes->setObjectName("yes");
        yes->setFont(font3);
        yes->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	background-color: rgb(59, 60, 54);\n"
"	color: white;\n"
"}"));

        horizontalLayout_2->addWidget(yes);

        no = new QRadioButton(layoutWidget_3);
        no->setObjectName("no");
        no->setFont(font3);
        no->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	background-color: rgb(59, 60, 54);\n"
"	color: white;\n"
"}"));

        horizontalLayout_2->addWidget(no);

        label_13 = new QLabel(DepositWindow);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(310, 180, 170, 35));
        label_13->setFont(font1);
        label_13->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        taxRate = new QLineEdit(DepositWindow);
        taxRate->setObjectName("taxRate");
        taxRate->setGeometry(QRect(175, 180, 130, 35));
        taxRate->setFont(font);
        label_14 = new QLabel(DepositWindow);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(5, 180, 165, 35));
        label_14->setFont(font2);
        label_14->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        label_15 = new QLabel(DepositWindow);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(5, 230, 170, 35));
        label_15->setFont(font2);
        label_15->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        resultSum = new QLineEdit(DepositWindow);
        resultSum->setObjectName("resultSum");
        resultSum->setGeometry(QRect(715, 480, 240, 35));
        resultSum->setFont(font);
        resultSum->setReadOnly(true);
        label_17 = new QLabel(DepositWindow);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(960, 480, 40, 35));
        label_17->setFont(font1);
        label_17->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        label_18 = new QLabel(DepositWindow);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(520, 480, 191, 35));
        label_18->setFont(font2);
        label_18->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        addPayment = new QPushButton(DepositWindow);
        addPayment->setObjectName("addPayment");
        addPayment->setGeometry(QRect(620, 30, 30, 30));
        addPayment->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 160, 122);\n"
"  color: black; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        verticalLayoutWidget = new QWidget(DepositWindow);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(520, 60, 451, 151));
        addLayout = new QVBoxLayout(verticalLayoutWidget);
        addLayout->setObjectName("addLayout");
        addLayout->setContentsMargins(0, 0, 0, 0);
        scrollPayment = new QScrollArea(verticalLayoutWidget);
        scrollPayment->setObjectName("scrollPayment");
        scrollPayment->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 447, 147));
        scrollPayment->setWidget(scrollAreaWidgetContents);

        addLayout->addWidget(scrollPayment);

        label_19 = new QLabel(DepositWindow);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(520, 30, 90, 30));
        label_19->setFont(font2);
        label_19->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        deletePayment = new QPushButton(DepositWindow);
        deletePayment->setObjectName("deletePayment");
        deletePayment->setGeometry(QRect(660, 30, 30, 30));
        deletePayment->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 160, 122);\n"
"  color: black; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        deleteWaste = new QPushButton(DepositWindow);
        deleteWaste->setObjectName("deleteWaste");
        deleteWaste->setGeometry(QRect(700, 230, 30, 30));
        deleteWaste->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 160, 122);\n"
"  color: black; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        addWaste = new QPushButton(DepositWindow);
        addWaste->setObjectName("addWaste");
        addWaste->setGeometry(QRect(660, 230, 30, 30));
        addWaste->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 160, 122);\n"
"  color: black; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        label_20 = new QLabel(DepositWindow);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(520, 230, 135, 30));
        label_20->setFont(font2);
        label_20->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        verticalLayoutWidget_2 = new QWidget(DepositWindow);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(520, 260, 451, 151));
        wasteLayout = new QVBoxLayout(verticalLayoutWidget_2);
        wasteLayout->setObjectName("wasteLayout");
        wasteLayout->setContentsMargins(0, 0, 0, 0);
        scrollWaste = new QScrollArea(verticalLayoutWidget_2);
        scrollWaste->setObjectName("scrollWaste");
        scrollWaste->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 447, 147));
        scrollWaste->setWidget(scrollAreaWidgetContents_2);

        wasteLayout->addWidget(scrollWaste);

        periodCombo = new QComboBox(DepositWindow);
        periodCombo->setObjectName("periodCombo");
        periodCombo->setGeometry(QRect(175, 235, 135, 25));
        periodCombo->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	background-color: rgb(59, 60, 54);\n"
"	color: white;\n"
"}"));

        retranslateUi(DepositWindow);

        QMetaObject::connectSlotsByName(DepositWindow);
    } // setupUi

    void retranslateUi(QDialog *DepositWindow)
    {
        DepositWindow->setWindowTitle(QCoreApplication::translate("DepositWindow", "Deposit Calculator (by Stephank)", nullptr));
        calculator->setText(QCoreApplication::translate("DepositWindow", "\320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        creditCalc->setText(QCoreApplication::translate("DepositWindow", "\320\232\321\200\320\265\320\264\320\270\321\202\320\275\321\213\320\271 \320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        showResult->setText(QCoreApplication::translate("DepositWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_12->setText(QCoreApplication::translate("DepositWindow", "\320\240\321\203\320\261.", nullptr));
        label->setText(QCoreApplication::translate("DepositWindow", "\320\241\321\203\320\274\320\274\320\260 \320\262\320\272\320\273\320\260\320\264\320\260:", nullptr));
        label_6->setText(QCoreApplication::translate("DepositWindow", "\320\235\320\260\321\207\320\270\321\201\320\273\320\265\320\275\320\275\321\213\320\265 \320\277\321\200\320\276\321\206\320\265\320\275\321\202\321\213:", nullptr));
        label_8->setText(QCoreApplication::translate("DepositWindow", "% \320\263\320\276\320\264\320\276\320\262\321\213\321\205", nullptr));
        label_10->setText(QCoreApplication::translate("DepositWindow", "\320\240\321\203\320\261.", nullptr));
        label_4->setText(QCoreApplication::translate("DepositWindow", "\320\232\320\260\320\277\320\270\321\202\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217 \320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\276\320\262:", nullptr));
        label_5->setText(QCoreApplication::translate("DepositWindow", "\320\224\320\276\321\205\320\276\320\264 \320\267\320\260 \320\262\321\213\321\207\320\265\321\202\320\276\320\274 \320\275\320\260\320\273\320\276\320\263\320\276\320\262:", nullptr));
        day->setText(QCoreApplication::translate("DepositWindow", "\320\224\320\265\320\275\321\214", nullptr));
        month->setText(QCoreApplication::translate("DepositWindow", "\320\234\320\265\321\201\321\217\321\206", nullptr));
        year->setText(QCoreApplication::translate("DepositWindow", "\320\223\320\276\320\264", nullptr));
        label_3->setText(QCoreApplication::translate("DepositWindow", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260:", nullptr));
        label_11->setText(QCoreApplication::translate("DepositWindow", "\320\240\321\203\320\261.", nullptr));
        label_9->setText(QCoreApplication::translate("DepositWindow", "\320\240\321\203\320\261.", nullptr));
        label_7->setText(QCoreApplication::translate("DepositWindow", "\320\235\320\260\320\273\320\276\320\263:", nullptr));
        label_2->setText(QCoreApplication::translate("DepositWindow", "\320\241\321\200\320\276\320\272 \321\200\320\260\320\267\320\274\320\265\321\211\320\265\320\275\320\270\321\217:", nullptr));
        yes->setText(QCoreApplication::translate("DepositWindow", "\320\224\320\260", nullptr));
        no->setText(QCoreApplication::translate("DepositWindow", "\320\235\320\265\321\202", nullptr));
        label_13->setText(QCoreApplication::translate("DepositWindow", "%", nullptr));
        taxRate->setText(QString());
        label_14->setText(QCoreApplication::translate("DepositWindow", "\320\235\320\260\320\273\320\276\320\263\320\276\320\262\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260:", nullptr));
        label_15->setText(QCoreApplication::translate("DepositWindow", "\320\237\320\265\321\200\320\270\320\276\320\264\320\270\321\207\320\275\320\276\321\201\321\202\321\214 \320\262\321\213\320\277\320\273\320\260\321\202:", nullptr));
        resultSum->setText(QString());
        label_17->setText(QCoreApplication::translate("DepositWindow", "\320\240\321\203\320\261.", nullptr));
        label_18->setText(QCoreApplication::translate("DepositWindow", "\320\241\321\203\320\274\320\274\320\260 \320\272 \320\272\320\276\320\275\321\206\321\203 \321\201\321\200\320\276\320\272\320\260:", nullptr));
        addPayment->setText(QCoreApplication::translate("DepositWindow", "+", nullptr));
        label_19->setText(QCoreApplication::translate("DepositWindow", "\320\237\320\276\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217:", nullptr));
        deletePayment->setText(QCoreApplication::translate("DepositWindow", "-", nullptr));
        deleteWaste->setText(QCoreApplication::translate("DepositWindow", "-", nullptr));
        addWaste->setText(QCoreApplication::translate("DepositWindow", "+", nullptr));
        label_20->setText(QCoreApplication::translate("DepositWindow", "\320\247\320\260\321\201\321\202\320\270\321\207\320\275\321\213\320\265 \321\201\320\275\321\217\321\202\320\270\321\217:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DepositWindow: public Ui_DepositWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOSITWINDOW_H
