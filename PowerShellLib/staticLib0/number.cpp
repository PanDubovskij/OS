#include "number.h"

namespace MyLib
{
    NumberLib::NumberLib(double n)
    {
        number = n;
    }

    double NumberLib::getDouble()
    {
        return this->number;
    }

    NumberLib& NumberLib::operator=(NumberLib& n)
    {
        number = n.number;
        return (*this);
    }

    NumberLib NumberLib::operator+(const NumberLib& n)
    {
        return NumberLib(number + n.number);
    }

    NumberLib NumberLib::operator-(const NumberLib& n)
    {
        return NumberLib(number - n.number);
    }

    NumberLib NumberLib::operator*(const NumberLib& n)
    {
        return NumberLib(number * n.number);
    }

    NumberLib NumberLib::operator/(const NumberLib& n)
    {
        return NumberLib(number / n.number);
    }

    double NumberLib::Add(double a, double b)
    {
        return a + b;
    }

    double NumberLib::Substract(double a, double b)
    {
        return a - b;
    }

    double NumberLib::Multiply(double a, double b)
    {
        return a * b;
    }
    
    double NumberLib::Divide(double a, double b)
    {
        return a / b;
    }

    std::ostream& operator<<(std::ostream& out, const NumberLib& n)
    {
        out << n.number;
        return out;
    }
    std::istream& operator>>(std::istream& in, NumberLib& n)
    {
        in >> n.number;
        return in;
    }
    NumberLib createNumber(double number)
    {
        return NumberLib(number);
    }
}