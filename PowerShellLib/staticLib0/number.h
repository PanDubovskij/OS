#pragma once
#include <fstream>

namespace MyLib
{
	class NumberLib
	{
	private:
		double number = 0.;
	public:
		NumberLib() {
			number = 0.;
		};
		NumberLib(double number);
		~NumberLib() {}

		double getDouble();

		NumberLib& operator=(NumberLib& n);
		NumberLib operator+(const NumberLib& n);
		NumberLib operator-(const NumberLib& n);
		NumberLib operator*(const NumberLib& n);
		NumberLib operator/(const NumberLib& n);

		friend std::ostream& operator<< (std::ostream&, const NumberLib&);
		friend std::istream& operator>> (std::istream&, NumberLib&);

		static double Add(double a, double b);
		static double Substract(double a, double b);
		static double Multiply(double a, double b);
		static double Divide(double a, double b);
	};
		
	const NumberLib ZERO(0);
	const NumberLib ONE(1);
	NumberLib createNumber(double number);
}