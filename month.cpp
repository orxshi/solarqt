#include "main.h"
#include <iostream>

void Sol::make_month_day()
{
    for (int n=0; n<365; ++n)
    {
        if (n < 10)
        {
            month_day.push_back(std::make_tuple(n, 3, 22 + n));
        }
        else if (n < 40)
        {
            month_day.push_back(std::make_tuple(n, 4, n - 9));
        }
        else if (n < 71)
        {
            month_day.push_back(std::make_tuple(n, 5, n - 39));
        }
        else if (n < 101)
        {
            month_day.push_back(std::make_tuple(n, 6, n - 70));
        }
        else if (n < 132)
        {
            month_day.push_back(std::make_tuple(n, 7, n - 100));
        }
        else if (n < 163)
        {
            month_day.push_back(std::make_tuple(n, 8, n - 131));
        }
        else if (n < 193)
        {
            month_day.push_back(std::make_tuple(n, 9, n - 162));
        }
        else if (n < 224)
        {
            month_day.push_back(std::make_tuple(n, 10, n - 192));
        }
        else if (n < 254)
        {
            month_day.push_back(std::make_tuple(n, 11, n - 223));
        }
        else if (n < 285)
        {
            month_day.push_back(std::make_tuple(n, 12, n - 253));
        }
        else if (n < 316)
        {
            month_day.push_back(std::make_tuple(n, 1, n - 284));
        }
        else if (n < 344)
        {
            month_day.push_back(std::make_tuple(n, 2, n - 315));
        }
        else if (n < 365)
        {
            month_day.push_back(std::make_tuple(n, 3, n - 343));
        }
    }

//    for (int n=0; n<days.size(); ++n)
//    {
//        std::cout << std::get<0>(month_day[n]) << " " << std::get<1>(month_day[n]) << " " << std::get<2>(month_day[n]) << std::endl;
//    }
}

int Sol::get_N(Month month, DayOfMonth day)
{
    for (auto md: month_day)
    {
        if (std::get<1>(md) == month)
        {
            if (std::get<2>(md) == day)
            {
                return std::get<0>(md);
            }
        }
    }

    return -1;
}

Month Sol::get_month(Day N)
{
    for (auto md: month_day)
    {
        if (std::get<0>(md) == N)
        {
            return std::get<1>(md);
        }
    }

    return -1;
}
