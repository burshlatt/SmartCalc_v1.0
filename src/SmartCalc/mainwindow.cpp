#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(480, 380);

    QSettings settings("Trolltech", "Application Example");
    QPoint pos = settings.value("pos", QPoint(1000, 400)).toPoint();
    move(pos);

    ui->xValue->setText("0");
    ui->xMinCord->setText("-5");
    ui->xMaxCord->setText("5");
    ui->yMinCord->setText("-5");
    ui->yMaxCord->setText("5");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_num_0_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + "0");
        count_of_actions++;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_num_1_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + "1");
        count_of_actions++;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_num_2_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + "2");
        count_of_actions++;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_num_3_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + "3");
        count_of_actions++;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_num_4_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + "4");
        count_of_actions++;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_num_5_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + "5");
        count_of_actions++;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_num_6_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + "6");
        count_of_actions++;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_num_7_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + "7");
        count_of_actions++;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_num_8_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + "8");
        count_of_actions++;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_num_9_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + "9");
        count_of_actions++;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_addFunc_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + "+");
        count_of_actions++;
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
    char *chars_array = &final_string[0];
    char operators[6] = {'+', '-', '*', '/', '^', 'd'};
    if (count_of_actions < 255) {
        for (int i = 0; i < 6; i++) {
            if (chars_array[strlen(chars_array) - 1] == operators[i]) {
                ui->inputOutput->setText(ui->inputOutput->text() + "(");
            }
        }
        if (count_of_actions == 0) {
            ui->inputOutput->setText(ui->inputOutput->text() + "(");
            count_of_actions++;
        }
        ui->inputOutput->setText(ui->inputOutput->text() + "-");
        count_of_actions++;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_mulFunc_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + "*");
        count_of_actions++;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_divFunc_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + "/");
        count_of_actions++;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_cosFunc_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + "cos(");
        count_of_actions++;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_sinFunc_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + "sin(");
        count_of_actions++;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_tanFunc_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + "tan(");
        count_of_actions++;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_sqrtFunc_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + "sqrt(");
        count_of_actions++;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_lnFunc_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + "ln(");
        count_of_actions++;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_logFunc_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + "log(");
        count_of_actions++;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_acosFunc_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + "acos(");
        count_of_actions++;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_asinFunc_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + "asin(");
        count_of_actions++;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_atanFunc_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + "atan(");
        count_of_actions++;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_powFunc_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + "^");
        count_of_actions++;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_modFunc_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + "mod");
        count_of_actions++;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_leftBracket_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + "(");
        count_of_actions++;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_rightBracket_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + ")");
        count_of_actions++;
    } else {
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + "ERROR: Too many elements!");
    }
}

void MainWindow::on_xSym_clicked() {
    if (count_of_actions == 0) {
        ui->inputOutput->clear();
    }
    if (count_of_actions < 255) {
        ui->inputOutput->setText(ui->inputOutput->text() + "x");
        count_of_actions++;
        is_x = 1;
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
    double xValue = ui->xValue->text().toDouble();
    std::string final_string = ui->inputOutput->text().toStdString();
    char *chars_array = &final_string[0];
    double result = polish_notation(chars_array, is_x, xValue);
    if (is_x) {
        print_graph(result);
        is_x = 0;
    } else {
        QString result_string = QString::number(result);
        ui->inputOutput->clear();
        ui->inputOutput->setText(ui->inputOutput->text() + result_string);
        count_of_actions = 0;
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
