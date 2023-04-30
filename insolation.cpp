#include "main.h"
#include <iostream>

TimeOfYear get_time_of_year(int N) // N is the number of days from spring equinox
{
    return 2 * PI * double(N) / DAYS_IN_YEAR;
}

Declination get_declination(TimeOfYear time_of_year)
{
    return std::asin(std::sin(EARTH_TILT) * std::sin(time_of_year));
}

TimeOfDay get_time_of_day(Hour t) // t is zero at solar noon.
{
    return 2 * PI * t / HOURS_IN_DAY;
}

Radian get_angle_of_incidence(Latitude lambda, Declination delta, TimeOfDay t, TimeOfYear alpha)
{
    Radian a = alpha + t;
    return std::acos(std::cos(lambda - delta) * (std::cos(alpha) * std::cos(a) + std::sin(alpha) * std::sin(a)));
}

Insolation Sol::hourly_insolation(AngleOfIncidence beta)
{
    return INSOLATION * std::cos(beta) * hour_inc / 1000;
}

Insolation Sol::daily_insolation(Declination delta, TimeOfYear toy, PanelTiltAngle theta)
{
    AngleOfIncidence beta;
    Insolation di = 0;

    for (double h: hours)
    {
        TimeOfDay tod = get_time_of_day(h);

        beta = get_angle_of_incidence(CYPRUS_LATITUDE, delta, tod, toy);

        if (std::cos(beta) < 0.)
        {
            continue;
        }

        beta = get_angle_of_incidence(CYPRUS_LATITUDE - theta, delta, tod, toy);

        if (std::cos(beta) < 0.)
        {
            continue;
        }

        di += hourly_insolation(beta);
        //dt += hour_inc;
    }

    return di;
}

Insolation Sol::annual_insolation(Day day_min, Day day_max, PanelTiltAngle theta)
{
    Insolation annual_inso = 0.;
    insolations.clear();

    for (Day d: days)
    {
        if (d < day_min || d > day_max)
        {
            continue;
        }

        TimeOfYear toy = get_time_of_year(d);
        Declination delta = get_declination(toy);

        //double I = 0.;
        //double dt = 0.;

        Insolation di = daily_insolation(delta, toy, theta);

        annual_inso += di;
        insolations.push_back(di);
        //daytime.push_back(dt);
    }

    return annual_inso;
}

