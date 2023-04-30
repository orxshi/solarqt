#include "mainwindow.h"
#include "ui_mainwindow.h"

QChart* chart_it;
QValueAxis* x_axis;
QValueAxis* y_axis;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    chart_it = new QChart();
    chart_it->setTitle("Insolation vs Panel Tilt Angle");
    x_axis = new QValueAxis();
    y_axis = new QValueAxis();
    x_axis->setTitleText("Theta");
    y_axis->setTitleText("Insolation");
    chart_it->addAxis(x_axis, Qt::AlignBottom);
    chart_it->addAxis(y_axis, Qt::AlignLeft);

    ui->graphicsView->setChart(chart_it);

}

MainWindow::~MainWindow()
{
    delete ui;
}
