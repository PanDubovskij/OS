// MathLibrary.cpp : Defines the exported functions for the DLL.
#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include "Vector.h"

namespace MyLib
{

    Vector::Vector(NumberLib x, NumberLib y)
    {
        _x = x;
        _y = y;
    }
    DLL1_API NumberLib Vector::getX()
    {
        return NumberLib(_x);
    }
    DLL1_API NumberLib Vector::getY()
    {
        return NumberLib(_y);
    }
    DLL1_API Vector& Vector::operator=(Vector& v)
    {
        _x = v._x;
        _y = v._y;
        return (*this);
    }
    DLL1_API Vector Vector::operator+(const Vector& v)
    {
        return Vector(_x + v._x, _y + v._y);
    }
    DLL1_API NumberLib Vector::Radius()
    {
        return NumberLib(sqrt(_x.getDouble()* _x.getDouble()+ _y.getDouble()*_y.getDouble()));
    }
    DLL1_API NumberLib Vector::Angle()
    {
        return NumberLib(asin(_y.getDouble()/Radius().getDouble()));
    }
    std::ostream& operator<<(std::ostream& out, const Vector& v)
    {
        out << v._x << v._y;
        return out;
    }
    std::istream& operator>>(std::istream& in, Vector& v)
    {
        in >> v._x >> v._y;
        return in;
    }
}