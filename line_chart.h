#ifndef LINE_CHART_H
#define LINE_CHART_H

#include <QtCharts>

struct LineChart: QChart
{
    QValueAxis* x_axis;
    QValueAxis* y_axis;

    //std::vector<QLineSeries> series;

    LineChart();

    void set_axes_extrema();
    void add_series(QLineSeries* series);
    void set_x_axis_title(QString title);
    void set_y_axis_title(QString title);
};

#endif // LINE_CHART_H
