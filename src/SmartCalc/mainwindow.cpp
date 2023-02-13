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

    connect(ui->lnFunc, SIGNAL(clicked()), this, SLOT(func_clicked()));
    connect(ui->logFunc, SIGNAL(clicked()), this, SLOT(func_clicked()));
    connect(ui->absFunc, SIGNAL(clicked()), this, SLOT(func_clicked()));
    connect(ui->cosFunc, SIGNAL(clicked()), this, SLOT(func_clicked()));
    connect(ui->sinFunc, SIGNAL(clicked()), this, SLOT(func_clicked()));
    connect(ui->tanFunc, SIGNAL(clicked()), this, SLOT(func_clicked()));
    connect(ui->acosFunc, SIGNAL(clicked()), this, SLOT(func_clicked()));
    connect(ui->asinFunc, SIGNAL(clicked()), this, SLOT(func_clicked()));
    connect(ui->atanFunc, SIGNAL(clicked()), this, SLOT(func_clicked()));
    connect(ui->sqrtFunc, SIGNAL(clicked()), this, SLOT(func_clicked()));

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
    connect(ui->num_pi, SIGNAL(clicked()), this, SLOT(symbols_clicked()));

    connect(ui->addFunc, SIGNAL(clicked()), this, SLOT(operators_clicked()));
    connect(ui->mulFunc, SIGNAL(clicked()), this, SLOT(operators_clicked()));
    connect(ui->divFunc, SIGNAL(clicked()), this, SLOT(operators_clicked()));
    connect(ui->powFunc, SIGNAL(clicked()), this, SLOT(operators_clicked()));
    connect(ui->modFunc, SIGNAL(clicked()), this, SLOT(operators_clicked()));

    connect(ui->leftBracket, SIGNAL(clicked()), this, SLOT(brackets_clicked()));
    connect(ui->rightBracket, SIGNAL(clicked()), this, SLOT(brackets_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::operators_clicked() {
    int already = 0;
    decompose_func();
    if (count_of_actions != 0 && last_symbol != '(') {
        for (int i = 0; i < 6; i++) {
            if (last_symbol == operators[i]) {
                already = 1;
            }
        }
        if (already) {
            if (last_symbol == 'd') {
                on_delElem_clicked();
                on_delElem_clicked();
            }
            on_delElem_clicked();
        }
        if (count_of_actions > 0 && count_of_actions < 255) {
            ui->inputOutput->setText(ui->inputOutput->text() + button->text());
            count_of_actions += button->text().size();
        }
    }
}

void MainWindow::symbols_clicked() {
    decompose_func();
    if (count_of_actions < 255) {
        if (last_symbol == 'x' || last_symbol == ')') {
            ui->inputOutput->setText(ui->inputOutput->text() + "*");
            count_of_actions++;
        }
        if (button->text() == "Pi") {
            if (last_symbol > '0' && last_symbol < '9') {
                ui->inputOutput->setText(ui->inputOutput->text() + "*");
            }
            ui->inputOutput->setText(ui->inputOutput->text() + "3.141592");
            count_of_actions += 8;
        } else if (button->text() == 'x') {
            if (last_symbol > '0' && last_symbol < '9') {
                ui->inputOutput->setText(ui->inputOutput->text() + "*");
            }
            ui->inputOutput->setText(ui->inputOutput->text() + "x");
            count_of_actions += 1;
        } else {
            ui->inputOutput->setText(ui->inputOutput->text() + button->text());
            count_of_actions += 1;
        }
    }
}

void MainWindow::func_clicked() {
    decompose_func();
    if (count_of_actions < 255) {
        if ((last_symbol > '0' && last_symbol < '9') || last_symbol == ')') {
            ui->inputOutput->setText(ui->inputOutput->text() + "*");
            count_of_actions++;
        }
        ui->inputOutput->setText(ui->inputOutput->text() + button->text() + "(");
        count_of_actions += button->text().size() + 1;
    }
}

void MainWindow::brackets_clicked() {
    int can_do = 1;
    decompose_func();
    count_of_left_bracket = 0;
    count_of_right_bracket = 0;
    for (int i = 0; i < string_size; i++) {
        if (input_string[i] == '(') {
            count_of_left_bracket++;
        }
        if (input_string[i] == ')') {
            count_of_right_bracket++;
        }
    }
    if (count_of_actions < 255) {
        if (button->text() == '(') {
            if ((last_symbol > '0' && last_symbol < '9') || last_symbol == 'x' || last_symbol == ')') {
                ui->inputOutput->setText(ui->inputOutput->text() + "*");
                count_of_actions++;
            }
            ui->inputOutput->setText(ui->inputOutput->text() + "(");
            count_of_actions++;
        }
        if (button->text() == ')' && count_of_right_bracket < count_of_left_bracket) {
            for (int i = 0; i < 6; i++) {
                if (last_symbol == operators[i]) {
                    can_do = 0;
                }
            }
            if (can_do) {
                ui->inputOutput->setText(ui->inputOutput->text() + ")");
                count_of_actions++;
            }
        }
    }
}

void MainWindow::on_subFunc_clicked() {
    decompose_func();
    if (count_of_actions < 255) {
        if (count_of_actions == 0) {
            ui->inputOutput->setText(ui->inputOutput->text() + "(");
            count_of_actions++;
        } else {
            for (int i = 0; i < 6; i++) {
                if (last_symbol == operators[i]) {
                    ui->inputOutput->setText(ui->inputOutput->text() + "(");
                    count_of_actions++;
                    break;
                }
            }
        }
        ui->inputOutput->setText(ui->inputOutput->text() + "-");
        count_of_actions++;
    }
}

void MainWindow::on_dotSym_clicked() {
    decompose_func();
    if (count_of_actions < 255 && last_symbol != '.') {
        if (last_symbol < '0' || last_symbol > '9') {
            ui->inputOutput->setText(ui->inputOutput->text() + "0");
            count_of_actions++;
        }
        ui->inputOutput->setText(ui->inputOutput->text() + ".");
        count_of_actions++;
    }
}

void MainWindow::decompose_func() {
    button = (QPushButton *)sender();
    input_string = ui->inputOutput->text().toStdString();
    last_symbol = input_string[input_string.size() - 1];
    string_size = input_string.size();
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    if (count_of_actions >= 255) {
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
    error_status = 0;
    int can_do = 1;
    double xValue = ui->xValue->text().toDouble();
    std::string final_string = ui->inputOutput->text().toStdString();
    char *chars_array = &final_string[0];
    double result = polish_notation(chars_array, is_x, xValue, &error_status);
    for (int i = 0; i < 6; i++) {
        if (final_string[final_string.size() - 1] == operators[i]) {
            can_do = 0;
        }
    }

     //sin(x)0.3 // от нажатия точки // 5.2.3+3

//    for (int i = 0; i < (int)final_string.size(); i++) {
//        if (chars_array[i] == '.') {
//            for (int j = i + 1; j < (int)final_string.size(); j++) {
//                if (chars_array[j] < '0' || chars_array[j] > '9') {
//                    i = j;
//                    break;
//                }
//            }
//            if (chars_array[i] == '.') {
//                can_do = 0;
//                break;
//            }
//        }
//    }
    for (int i = 0; final_string[i] != '\0'; i++) {
        if (final_string[i] == 'x') {
            is_x = 1;
        }
    }
    if (!error_status && can_do) {
        if (is_x) {
            if (!graph_is_open) {
                int xPos = this->geometry().x();
                int yPos = this->geometry().y();
                this->setFixedSize(960, 380);
                ui->showGraph->setText("<");
                setGeometry(xPos, yPos, width() + 480, height());
                graph_is_open = 1;
            }
            print_graph(chars_array);
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

void MainWindow::print_graph(char *chars_array) {
    ui->functionGraph->clearGraphs();
    int xMin = ui->xMinCord->text().toInt();
    int xMax = ui->xMaxCord->text().toInt();
    int yMin = ui->yMinCord->text().toInt();
    int yMax = ui->yMaxCord->text().toInt();
    ui->functionGraph->xAxis->setRange(xMin, xMax);
    ui->functionGraph->yAxis->setRange(yMin, yMax);
    double h = 0.01;
    double xBegin = -200;
    double xEnd = 200 + h;
    double X = xBegin;
    QVector<double> xCord, yCord;
    while (X <= xEnd) {
        double result = polish_notation(chars_array, is_x, X, &error_status);
        xCord.push_back(X);
        yCord.push_back(result);
        X += h;
    }
    ui->functionGraph->addGraph();
    ui->functionGraph->graph(0)->addData(xCord, yCord);
    ui->functionGraph->replot();
}
