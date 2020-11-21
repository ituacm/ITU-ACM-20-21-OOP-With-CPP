#include <iostream>

class Linear
{
private:
    double m;
    double n;
public:
    Linear(double m = 0, double n = 0)
        :m(m), n(n)
    {}

    double solveAt(double x)
    {
        return m*x+n;
    }

    double operator()(double x)
    {
        return m*x+n;
    }

    friend std::ostream& operator<<(std::ostream& os, const Linear& l)
    {
        return os << l.m << "x + " << l.n;
    }
};