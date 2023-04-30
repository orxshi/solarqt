#include "solar.h"
#include "./ui_solar.h"
#include "line_chart.h"
#include "main.h"
#include <iostream>
#include <QtConcurrent>

Sol* sol;

LineChart* chart_di;
LineChart* chart_ti;

Insolation INSOLATION = 1366;

void make_empty_day_insolation_chart()
{
    chart_di = new LineChart();

    chart_di->set_x_axis_title("Day");
    chart_di->set_y_axis_title("Insolation (kWh/m2)");

    QLineSeries* series = new QLineSeries();

    chart_di->add_series(series);
    chart_di->removeSeries(series);

    delete series;
}

void make_empty_tilt_insolation_chart()
{
    chart_ti = new LineChart();

    chart_ti->set_x_axis_title("Tilt (deg)");
    chart_ti->set_y_axis_title("Insolation (kWh/m2)");

    QLineSeries* series = new QLineSeries();

    chart_ti->add_series(series);
    chart_ti->removeSeries(series);

    delete series;
}

//int Sol::progress(int arg)
//{
//    return arg;
//}

void Sol::calc_tilt_insolation()
{
    annual_insos.clear();

    int i = 0;
    for (PanelTiltAngle theta: thetas)
    {
        Insolation annual_inso = annual_insolation(days.front(), days.back(), theta);

        annual_insos.push_back(annual_inso);

        ++i;

        emit progress(i);
    }
}

//void calc_tilt_insolation()
//{
//    sol->annual_insos.clear();

//    int i = 0;
//    for (PanelTiltAngle theta: sol->thetas)
//    {
//        Insolation annual_inso = sol->annual_insolation(sol->days.front(), sol->days.back(), theta);

//        sol->annual_insos.push_back(annual_inso);

//        ++i;

//        emit progress(i);
//    }
//}

Solar::Solar(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Solar)
{
    ui->setupUi(this);

    sol = new Sol();

    this->setStyleSheet("background-color: lightblue;");

    make_empty_day_insolation_chart();
    make_empty_tilt_insolation_chart();

    ui->graphicsView->setChart(chart_di);
    ui->chart_tiltinso->setChart(chart_ti);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->chart_tiltinso->setRenderHint(QPainter::Antialiasing);

    ui->dsb_io->setValue(INSOLATION);
    ui->progressBar->setValue(0);
}

void Solar::draw_tilt_insolation()
{
    chart_ti->removeAllSeries();

    QLineSeries* series = new QLineSeries();
    for (int i=0; i<sol->thetas.size(); ++i)
    {
        series->append(RAD_TO_DEG(sol->thetas[i]), sol->annual_insos[i]);
    }

    chart_ti->add_series(series);
}

Solar::~Solar()
{
    delete ui;
}

void Solar::setProgress(int progress)
{
    ui->progressBar->setValue(progress);
}

void Solar::on_pb_tilt_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("This may take a while. Continue?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    int ret = msgBox.exec();

    switch (ret)
    {
    case QMessageBox::Yes:
        break;
    case QMessageBox::Cancel:
        return;
    }

    //QFuture<void> future = QtConcurrent::run(calc_tilt_insolation);
    //QFuture<void> future = QtConcurrent::run(sol, &Sol::calc_tilt_insolation);
    //QFuture<void> future = QtConcurrent::run(&Sol::calc_tilt_insolation);

    ui->progressBar->setValue(0);


    QFuture<void> future = QtConcurrent::run(&Sol::calc_tilt_insolation, sol);

    QFutureWatcher<void> *watcher = new QFutureWatcher<void>(this);

    connect(watcher, &QFutureWatcher<void>::finished, this, &Solar::draw_tilt_insolation);


    //connect(watcher, SIGNAL(finished()), this, SLOT(draw_tilt_insolation()));

    //connect(watcher, SIGNAL(progress(int arg)), this, SLOT(setProgress(int)));
    //connect(watcher, &Sol::progress, this, SLOT(setProgress(int)));
    connect(sol, &Sol::progress, this, &Solar::setProgress);






    connect(watcher, SIGNAL(finished()), watcher, SLOT(deleteLater()));



    //connect(watcher, SIGNAL(progress(int)), this, SLOT(setValue(int)));
    //connect(watcher, &MainWindow::computationProgress, this, SLOT(setProgress));


    watcher->setFuture(future);
}

void Solar::on_pb_di_clicked()
{
    Degree tilt_deg = ui->dsb_tilt->value();
    PanelTiltAngle tilt = DEG_TO_RAD(ui->dsb_tilt->value());

    sol->annual_insolation(sol->days.front(), sol->days.back(), tilt);

    QLineSeries* series = new QLineSeries();
    series->setName(QString::number(tilt_deg));

    for (int j=0; j<sol->days.size(); ++j)
    {
        Day d = sol->days[j];
        Insolation I = sol->insolations[j];

        series->append(d, I);
    }

    chart_di->add_series(series);

    chart_di->legend()->setVisible(true);
}

void Solar::on_dsb_io_valueChanged(double arg1)
{
    INSOLATION = ui->dsb_io->value();
}



