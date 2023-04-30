#ifndef GLOBAL_H
#define GLOBAL_H

#include "alias.h"
#include <vector>
#include <tuple>

extern std::vector<Day> days;
extern std::vector<Hour> hours;
extern std::vector<Insolation> insolations;
extern std::vector<Hour> daytime;
extern std::vector<Radian> thetas;
extern std::vector<std::tuple<int, int, int>> month_day;
extern std::vector<double> betas;
extern Hour hour_inc;

#endif // GLOBAL_H
