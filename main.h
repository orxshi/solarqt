#ifndef SOL_H
#define SOL_H

#include "alias.h"
#include <vector>
#include <tuple>
#include "discretize.h"
#include "derived_constant.h"
#include <QObject>

struct Sol: public QObject
{

    Q_OBJECT

public:

    std::vector<Day> days;
    std::vector<Hour> hours;
    std::vector<Insolation> insolations;
    std::vector<Hour> daytime;
    std::vector<PanelTiltAngle> thetas;
    std::vector<std::tuple<Day, Month, DayOfMonth>> month_day;
    std::vector<Radian> betas;
    std::vector<Insolation> annual_insos;
    Hour hour_inc;

    Sol();
    void make_month_day();
    int get_N(Month month, DayOfMonth day);
    Month get_month(Day N);
    Insolation hourly_insolation(AngleOfIncidence beta);
    Insolation daily_insolation(Declination delta, TimeOfYear toy, PanelTiltAngle theta);
    Insolation annual_insolation(Day day_min, Day day_max, PanelTiltAngle theta);


    void calc_tilt_insolation();

signals:

    void progress(int arg);



};

#endif // SOL_H
