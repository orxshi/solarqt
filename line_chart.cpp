#include "line_chart.h"
#include <iostream>

LineChart::LineChart()
{
    x_axis = new QValueAxis();
    y_axis = new QValueAxis();

    x_axis->setLabelFormat("%i");
    y_axis->setLabelFormat("%i");

    this->addAxis(x_axis, Qt::AlignBottom);
    this->addAxis(y_axis, Qt::AlignLeft);

    this->legend()->setVisible(false);
}

void LineChart::set_axes_extrema()
{
    double xmin = 999999999999;
    double xmax = -99999999999;

    double ymin = 999999999999;
    double ymax = -99999999999;

    for (auto serie: this->series())
    {
        QLineSeries* lserie = static_cast<QLineSeries*>(serie);

        if (lserie->points().empty())
        {
            return;
        }

        for (auto p: lserie->points())
        {
            xmin = std::min(xmin, p.x());
            xmax = std::max(xmax, p.x());

            ymin = std::min(ymin, p.y());
            ymax = std::max(ymax, p.y());
        }
    }

    x_axis->setMin(xmin);
    x_axis->setMax(xmax);

    y_axis->setMin(ymin);
    y_axis->setMax(ymax);
}

void LineChart::add_series(QLineSeries* series)
{


    this->addSeries(series);

    series->attachAxis(x_axis);
    series->attachAxis(y_axis);

    set_axes_extrema();
}

void LineChart::set_x_axis_title(QString title)
{
    x_axis->setTitleText(title);
}

void LineChart::set_y_axis_title(QString title)
{
    y_axis->setTitleText(title);
}
