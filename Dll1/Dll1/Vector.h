#pragma once
#include "number.h"
//using namespace MyStaticLib;

#ifdef DLL1_EXPORTS
#define DLL1_API __declspec(dllexport)
#else
#define DLL1_API __declspec(dllimport)
#endif
namespace MyLib
{
	class Vector
	{
	private:
		NumberLib _x=ZERO;
		NumberLib _y=ZERO;
	public:
		DLL1_API Vector() {};
		DLL1_API Vector(NumberLib x, NumberLib y);
		DLL1_API ~Vector() {};

		DLL1_API NumberLib getX();
		DLL1_API NumberLib getY();

		DLL1_API Vector& operator=(Vector& v);
		DLL1_API Vector operator+(const Vector& v);

		DLL1_API NumberLib Radius();
		DLL1_API NumberLib Angle();

		DLL1_API friend std::ostream& operator<< (std::ostream& out, const Vector& v);
		DLL1_API friend std::istream& operator>> (std::istream& in, Vector& v);
	};

	const Vector ZERO_V(0,0);
	const Vector ONE_V(1,1);
}
