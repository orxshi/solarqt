#ifndef MACRO_H
#define MACRO_H

#include "constant.h"

constexpr Radian DEG_TO_RAD(Degree d) {
    return d * PI / 180;
}

constexpr Degree RAD_TO_DEG(Radian r) {
    return r * 180 / PI;
}

#endif // MACRO_H
