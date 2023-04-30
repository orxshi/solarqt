#ifndef CONSTANT_H
#define CONSTANT_H

#include "alias.h"
#include <cmath>

constexpr double PI = std::acos(-1);
const double DAYS_IN_YEAR = 365.24;
const Hour HOURS_IN_DAY = 24;
extern Insolation INSOLATION;
const Degree EARTH_TILT_DEG = 23.44;
const Degree CYPRUS_LATITUDE_DEG = 35.1264;

#endif // CONSTANT_H
