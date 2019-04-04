#include <iostream>
using namespace std;

int NOD(const int a, const int b)
{
	int t1 = a;
	int t2 = b;
	
	while (t1 > 0 && t2 > 0)
	{
		if (t1 > t2)
		{
			t1 %= t2;
		}
		else
		{
			t2 %= t1;
		}

	}
	
	return t1 + t2;
}

class Rational {
public:
	Rational() {
		_numerator = 0;
		_denominator = 1;
	}

	Rational(int numerator, int denominator) {
		bool negative = false;
		if (numerator < 0)
		{
			negative = !negative;
			if (denominator < 0)
				negative = !negative;
		}
		else if (denominator < 0)
		{
			negative = !negative;
		}
		int nod = NOD(abs(numerator), abs(denominator));
		_numerator = abs(numerator) / nod;
		_denominator = abs(denominator) / nod;
		if (negative) _numerator = -_numerator;
	}

	int Numerator() const {
		return _numerator;
	}

	int Denominator() const {
		return _denominator;
	}

	Rational operator+ (const Rational& rational)
	{
		return Rational((_numerator * rational.Denominator()) + (rational.Numerator() * _denominator), _denominator * rational.Denominator());
	}

	Rational operator- (const Rational& rational)
	{
		return Rational((_numerator * rational.Denominator()) - (rational.Numerator() * _denominator), _denominator * rational.Denominator());
	}

	Rational operator* (const Rational& rational)
	{
		return Rational(_numerator * rational.Numerator(), _denominator * rational.Denominator());
	}

	Rational operator/ (const Rational& rational)
	{
		return Rational(_numerator * rational.Denominator(), _denominator * rational.Numerator());
	}

	bool operator== (const Rational& rational)
	{
		return (_numerator == rational.Numerator() && _denominator == rational.Denominator());
	}

private:
	int _numerator;
	int _denominator;
};

int main() {
	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a * b;
		bool equal = c == Rational(8, 9);
		if (!equal) {
			cout << "2/3 * 4/3 != 8/9" << endl;
			return 1;
		}
	}

	{
		Rational a(5, 4);
		Rational b(15, 8);
		Rational c = a / b;
		bool equal = c == Rational(2, 3);
		if (!equal) {
			cout << "5/4 / 15/8 != 2/3" << endl;
			return 2;
		}
	}

	cout << "OK" << endl;
	return 0;
}