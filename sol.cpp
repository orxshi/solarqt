#include "main.h"

Sol::Sol()
{
    hours.resize(10000);
    generate(0.0, 24.0, hours);
    hour_inc = hours[1] - hours[0];

    days.resize(365);
    generate(0, 365, days);

    thetas.resize(100);
    generate(0, PI/2, thetas);

    make_month_day();
}
