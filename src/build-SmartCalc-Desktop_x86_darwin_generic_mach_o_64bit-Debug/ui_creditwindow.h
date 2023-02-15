/********************************************************************************
** Form generated from reading UI file 'creditwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDITWINDOW_H
#define UI_CREDITWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreditWindow
{
public:
    QLabel *label;
    QLineEdit *creditSum;
    QLabel *label_2;
    QLineEdit *creditTerm;
    QLabel *label_3;
    QLineEdit *percent;
    QLabel *label_4;
    QPushButton *showResult;
    QPushButton *calculator;
    QPushButton *deposCalc;
    QLabel *label_5;
    QLineEdit *resultSum;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *overPay;
    QLineEdit *monthRes;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *annu;
    QRadioButton *differ;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QRadioButton *month;
    QRadioButton *year;

    void setupUi(QDialog *CreditWindow)
    {
        if (CreditWindow->objectName().isEmpty())
            CreditWindow->setObjectName("CreditWindow");
        CreditWindow->resize(480, 480);
        CreditWindow->setMinimumSize(QSize(480, 480));
        CreditWindow->setMaximumSize(QSize(480, 480));
        CreditWindow->setStyleSheet(QString::fromUtf8("QDialog {\n"
"	background-color: rgb(255, 219, 139);\n"
"}"));
        label = new QLabel(CreditWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(5, 35, 170, 35));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        creditSum = new QLineEdit(CreditWindow);
        creditSum->setObjectName("creditSum");
        creditSum->setGeometry(QRect(175, 35, 130, 35));
        QFont font1;
        font1.setPointSize(17);
        creditSum->setFont(font1);
        label_2 = new QLabel(CreditWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(5, 85, 170, 35));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        creditTerm = new QLineEdit(CreditWindow);
        creditTerm->setObjectName("creditTerm");
        creditTerm->setGeometry(QRect(175, 85, 130, 35));
        creditTerm->setFont(font1);
        label_3 = new QLabel(CreditWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(5, 135, 170, 35));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        percent = new QLineEdit(CreditWindow);
        percent->setObjectName("percent");
        percent->setGeometry(QRect(175, 135, 130, 35));
        percent->setFont(font1);
        label_4 = new QLabel(CreditWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(5, 202, 210, 35));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        showResult = new QPushButton(CreditWindow);
        showResult->setObjectName("showResult");
        showResult->setGeometry(QRect(175, 265, 130, 40));
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
        calculator = new QPushButton(CreditWindow);
        calculator->setObjectName("calculator");
        calculator->setGeometry(QRect(0, 0, 240, 20));
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
        deposCalc = new QPushButton(CreditWindow);
        deposCalc->setObjectName("deposCalc");
        deposCalc->setGeometry(QRect(240, 0, 240, 20));
        deposCalc->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgb(255, 160, 122);\n"
"  color: black; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        label_5 = new QLabel(CreditWindow);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(5, 430, 170, 35));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        resultSum = new QLineEdit(CreditWindow);
        resultSum->setObjectName("resultSum");
        resultSum->setGeometry(QRect(175, 430, 260, 35));
        resultSum->setFont(font1);
        resultSum->setReadOnly(true);
        label_6 = new QLabel(CreditWindow);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(5, 330, 170, 35));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        label_7 = new QLabel(CreditWindow);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(5, 380, 170, 35));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        overPay = new QLineEdit(CreditWindow);
        overPay->setObjectName("overPay");
        overPay->setGeometry(QRect(175, 380, 260, 35));
        overPay->setFont(font1);
        overPay->setReadOnly(true);
        monthRes = new QLineEdit(CreditWindow);
        monthRes->setObjectName("monthRes");
        monthRes->setGeometry(QRect(175, 330, 260, 35));
        monthRes->setFont(font1);
        monthRes->setReadOnly(true);
        label_8 = new QLabel(CreditWindow);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(310, 135, 170, 35));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        label_9 = new QLabel(CreditWindow);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(310, 35, 170, 35));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        label_10 = new QLabel(CreditWindow);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(440, 330, 40, 35));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        label_11 = new QLabel(CreditWindow);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(440, 380, 40, 35));
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        label_12 = new QLabel(CreditWindow);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(440, 430, 40, 35));
        label_12->setFont(font);
        label_12->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: black; \n"
"}"));
        layoutWidget = new QWidget(CreditWindow);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(230, 190, 189, 61));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        annu = new QRadioButton(layoutWidget);
        annu->setObjectName("annu");
        QFont font2;
        font2.setPointSize(14);
        annu->setFont(font2);
        annu->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	color: black;\n"
"}"));

        verticalLayout->addWidget(annu);

        differ = new QRadioButton(layoutWidget);
        differ->setObjectName("differ");
        differ->setFont(font2);
        differ->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	color: black;\n"
"}"));

        verticalLayout->addWidget(differ);

        layoutWidget1 = new QWidget(CreditWindow);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(315, 85, 161, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        month = new QRadioButton(layoutWidget1);
        month->setObjectName("month");
        month->setFont(font2);
        month->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	color: black;\n"
"}"));

        horizontalLayout->addWidget(month);

        year = new QRadioButton(layoutWidget1);
        year->setObjectName("year");
        year->setFont(font2);
        year->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	color: black;\n"
"}"));

        horizontalLayout->addWidget(year);


        retranslateUi(CreditWindow);

        QMetaObject::connectSlotsByName(CreditWindow);
    } // setupUi

    void retranslateUi(QDialog *CreditWindow)
    {
        CreditWindow->setWindowTitle(QCoreApplication::translate("CreditWindow", "Credit Calculator (by Stephank)", nullptr));
        label->setText(QCoreApplication::translate("CreditWindow", "\320\241\321\203\320\274\320\274\320\260 \320\272\321\200\320\265\320\264\320\270\321\202\320\260:", nullptr));
        label_2->setText(QCoreApplication::translate("CreditWindow", "\320\241\321\200\320\276\320\272 \320\272\321\200\320\265\320\264\320\270\321\202\320\260:", nullptr));
        label_3->setText(QCoreApplication::translate("CreditWindow", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260:", nullptr));
        label_4->setText(QCoreApplication::translate("CreditWindow", "\320\242\320\270\320\277 \320\265\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320\275\321\213\321\205 \320\277\320\273\320\260\321\202\320\265\320\266\320\265\320\271:", nullptr));
        showResult->setText(QCoreApplication::translate("CreditWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        calculator->setText(QCoreApplication::translate("CreditWindow", "\320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        deposCalc->setText(QCoreApplication::translate("CreditWindow", "\320\224\320\265\320\277\320\276\320\267\320\270\321\202\320\275\321\213\320\271 \320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        label_5->setText(QCoreApplication::translate("CreditWindow", "\320\236\320\261\321\211\320\260\321\217 \320\262\321\213\320\277\320\273\320\260\321\202\320\260:", nullptr));
        label_6->setText(QCoreApplication::translate("CreditWindow", "\320\225\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320\275\321\213\320\271 \320\277\320\273\320\260\321\202\320\265\320\266:", nullptr));
        label_7->setText(QCoreApplication::translate("CreditWindow", "\320\237\320\265\321\200\320\265\320\277\320\273\320\260\321\202\320\260 \320\277\320\276 \320\272\321\200\320\265\320\264\320\270\321\202\321\203:", nullptr));
        label_8->setText(QCoreApplication::translate("CreditWindow", "%", nullptr));
        label_9->setText(QCoreApplication::translate("CreditWindow", "\320\240\321\203\320\261.", nullptr));
        label_10->setText(QCoreApplication::translate("CreditWindow", "\320\240\321\203\320\261.", nullptr));
        label_11->setText(QCoreApplication::translate("CreditWindow", "\320\240\321\203\320\261.", nullptr));
        label_12->setText(QCoreApplication::translate("CreditWindow", "\320\240\321\203\320\261.", nullptr));
        annu->setText(QCoreApplication::translate("CreditWindow", "\320\220\320\275\320\275\321\203\320\270\321\202\320\265\321\202\320\275\321\213\320\265", nullptr));
        differ->setText(QCoreApplication::translate("CreditWindow", "\320\224\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321\206\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\265", nullptr));
        month->setText(QCoreApplication::translate("CreditWindow", "\320\234\320\265\321\201\321\217\321\206\320\265\320\262", nullptr));
        year->setText(QCoreApplication::translate("CreditWindow", "\320\233\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreditWindow: public Ui_CreditWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDITWINDOW_H
