#pragma once
#include <cmath>
#include "number.h"
//using namespace MyStaticLib;

namespace MyLib
{
	class Vector
	{
	private:
		NumberLib _x=ZERO;
		NumberLib _y=ZERO;
	public:
		Vector() {};
		Vector(NumberLib x, NumberLib y);
		~Vector() {};

		NumberLib getX();
		NumberLib getY();

		Vector& operator=(Vector& v);
		Vector operator+(const Vector& v);

		NumberLib Radius();
		NumberLib Angle();

		friend std::ostream& operator<< (std::ostream& out, const Vector& v);
		friend std::istream& operator>> (std::istream& in, Vector& v);
	};

	const Vector ZERO_V(0,0);
	const Vector ONE_V(1,1);
}
