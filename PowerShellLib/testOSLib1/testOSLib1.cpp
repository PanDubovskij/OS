#include <iostream>
#include "Vector.h"
using namespace MyLib;

int main()
{
    NumberLib a(3);
    NumberLib b(6);
    NumberLib c = createNumber(8);
    std::cout << c << std::endl;
    std::cout << a + b << std::endl;
    std::cout << a - b << std::endl;
    std::cout << a * b << std::endl;
    std::cout << a / b << std::endl;

    Vector v1(createNumber(1), createNumber(5));
    Vector v2(createNumber(3), createNumber(8));
    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;
    std::cout << v1 + v2 << std::endl;
    std::cout << "phi=" << v1.Angle() << std::endl;
    std::cout << "r=" << v1.Radius() << std::endl;
    return 0;
}