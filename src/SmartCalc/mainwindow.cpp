#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(480, 380);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int x = (screenGeometry.width() - 480) / 2;
    int y = (screenGeometry.height() - 380) / 2;
    move(x, y);

    ui->xValue->setText("0");
    ui->xMaxCord->setText("5");
    ui->yMaxCord->setText("5");
    ui->xMinCord->setText("-5");
    ui->yMinCord->setText("-5");

    connect(ui->xSym, SIGNAL(clicked()), this, SLOT(symbols_clicked()));
    connect(ui->num_0, SIGNAL(clicked()), this, SLOT(symbols_clicked()));
    connect(ui->num_1, SIGNAL(clicked()), this, SLOT(symbols_clicked()));
    connect(ui->num_2, SIGNAL(clicked()), this, SLOT(symbols_clicked()));
    connect(ui->num_3, SIGNAL(clicked()), this, SLOT(symbols_clicked()));
    connect(ui->num_4, SIGNAL(clicked()), this, SLOT(symbols_clicked()));
    connect(ui->num_5, SIGNAL(clicked()), this, SLOT(symbols_clicked()));
    connect(ui->num_6, SIGNAL(clicked()), this, SLOT(symbols_clicked()));
    connect(ui->num_7, SIGNAL(clicked()), this, SLOT(symbols_clicked()));
    connect(ui->num_8, SIGNAL(clicked()), this, SLOT(symbols_clicked()));
    connect(ui->num_9, SIGNAL(clicked()), this, SLOT(symbols_clicked()));
    connect(ui->addFunc, SIGNAL(clicked()), this, SLOT(symbols_clicked()));
    connect(ui->mulFunc, SIGNAL(clicked()), this, SLOT(symbols_clicked()));
    connect(ui->divFunc, SIGNAL(clicked()), this, SLOT(symbols_clicked()));
    connect(ui->powFunc, SIGNAL(clicked()), this, SLOT(symbols_clicked()));
    connect(ui->modFunc, SIGNAL(clicked()), this, SLOT(symbols_clicked()));
    connect(ui->leftBracket, SIGNAL(clicked()), this, SLOT(symbols_clicked()));
    connect(ui->rightBracket, SIGNAL(clicked()), this, SLOT(symbols_clicked()));

    connect(ui->lnFunc, SIGNAL(clicked()), this, SLOT(func_clicked()));
    connect(ui->logFunc, SIGNAL(clicked()), this, SLOT(func_clicked()));
    connect(ui->cosFunc, SIGNAL(clicked()), this, SLOT(func_clicked()));
    connect(ui->sinFunc, SIGNAL(clicked()), this, SLOT(func_clicked()));
    connect(ui->tanFunc, SIGNAL(clicked()), this, SLOT(func_clicked()));
    connect(ui->acosFunc, SIGNAL(clicked()), this, SLOT(func_clicked()));
    connect(ui->asinFunc, SIGNAL(clicked()), this, SLOT(func_clicked()));
    connect(ui->atanFunc, SIGNAL(clicked()), this, SLOT(func_clicked()));
    connect(ui->sqrtFunc, SIGNAL(clicked()), this, SLOT(func_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::symbols_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    QPushButton *button = (QPushButton *)sender();
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + button->text());
        count_of_actions++;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::func_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    QPushButton *button = (QPushButton *)sender();
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + button->text() + "(");
        count_of_actions += button->text().size() + 1;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_subFunc_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    std::string final_string = ui->inputOutput->text().toStdString();
    char *last_symbol = &final_string[0];
    char operators[6] = {'+', '-', '*', '/', '^', 'd'};
    if (count_of_actions < 255) {
        if (count_of_actions == 0) {
            ui->inputOutput->setText(ui->inputOutput->text() + "(");
            count_of_actions++;
        } else {
            for (int i = 0; i < 6; i++) {
                if (last_symbol[strlen(last_symbol) - 1] == operators[i]) {
                    ui->inputOutput->setText(ui->inputOutput->text() + "(");
                    count_of_actions++;
                    break;
                }
            }
        }
        ui->inputOutput->setText(ui->inputOutput->text() + "-");
        count_of_actions++;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_dotSym_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    std::string final_string = ui->inputOutput->text().toStdString();
    if (count_of_actions <= 255 && final_string[final_string.size() - 1] != '.') {
        if (final_string[final_string.size() - 1] < '0' || final_string[final_string.size() - 1] > '9') {
            ui->inputOutput->setText(ui->inputOutput->text() + "0");
            count_of_actions++;
        }
        ui->inputOutput->setText(ui->inputOutput->text() + ".");
        count_of_actions++;
    } else if (count_of_actions > 255) {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_delElem_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    } else {
        if (count_of_actions > 0) {
            count_of_actions--;
        }
        QString text = ui->inputOutput->text();
        text.chop(1);
        ui->inputOutput->setText(text);
    }
}

void MainWindow::on_delAll_clicked() {
    is_x = 0;
    count_of_actions = 0;
    ui->inputOutput->clear();
}

void MainWindow::on_resultFunc_clicked() {
    int error_status = 0;
    double xValue = ui->xValue->text().toDouble();
    std::string final_string = ui->inputOutput->text().toStdString();
    char *chars_array = &final_string[0];
    double result = polish_notation(chars_array, is_x, xValue, &error_status);
    if (!error_status) {
        if (is_x) {
            print_graph(result);
            is_x = 0;
        } else {
            QString result_string = QString::number(result);
            ui->inputOutput->clear();
            ui->inputOutput->setText(ui->inputOutput->text() + result_string);
            count_of_actions = 0;
        }
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Incorrect data!");
    }
}

void MainWindow::on_showGraph_clicked() {
    int xPos = this->geometry().x();
    int yPos = this->geometry().y();
    if (!graph_is_open) {
        this->setFixedSize(960, 380);
        ui->showGraph->setText("<");
        setGeometry(xPos, yPos, width() + 480, height());
        graph_is_open = 1;
    } else {
        this->setFixedSize(480, 380);
        ui->showGraph->setText(">");
        setGeometry(xPos, yPos, width() - 480, height());
        graph_is_open = 0;
    }
}

void MainWindow::print_graph(double result) {
    ui->functionGraph->clearGraphs();
    int xMin = ui->xMinCord->text().toInt();
    int xMax = ui->xMaxCord->text().toInt();
    int yMin = ui->yMinCord->text().toInt();
    int yMax = ui->yMaxCord->text().toInt();
    ui->functionGraph->xAxis->setRange(xMin, xMax);
    ui->functionGraph->yAxis->setRange(yMin, yMax);
    h = 0.1;
    xBegin = xMin;
    xEnd = xMax + h;
    N = (xEnd - xBegin) / h + 2;
    for (X = xBegin; X <= xEnd; X += h) {
        xCord.push_back(X);
        yCord.push_back(result);
    }
    ui->functionGraph->addGraph();
    ui->functionGraph->graph(0)->addData(xCord, yCord);
    ui->functionGraph->replot();
}
