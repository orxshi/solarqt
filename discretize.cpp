#include "discretize.h"

void generate(double begin, double end, std::vector<double>& v)
{
    double inc = (end - begin) / v.size();

    for (int i=0; i<v.size(); ++i)
    {
        v[i] = i * inc;
    }
}

void generate(int begin, int end, std::vector<int>& v)
{
    double inc = (end - begin) / v.size();

    for (int i=0; i<v.size(); ++i)
    {
        v[i] = i * inc;
    }
}
