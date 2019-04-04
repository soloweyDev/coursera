#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <exception>

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
		if (denominator == 0)
		{
			throw invalid_argument("Invalid argument");
		}

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

	Rational operator+ (const Rational& rational) const
	{
		return Rational((_numerator * rational.Denominator()) + (rational.Numerator() * _denominator), _denominator * rational.Denominator());
	}

	Rational operator- (const Rational& rational) const
	{
		return Rational((_numerator * rational.Denominator()) - (rational.Numerator() * _denominator), _denominator * rational.Denominator());
	}

	Rational operator* (const Rational& rational) const
	{
		return Rational(_numerator * rational.Numerator(), _denominator * rational.Denominator());
	}

	Rational operator/ (const Rational& rational) const
	{
		if ((_denominator * rational.Numerator()) == 0)
		{
			throw domain_error("Division by zero");
		}
		return Rational(_numerator * rational.Denominator(), _denominator * rational.Numerator());
	}

	bool operator== (const Rational& rational) const
	{
		return (_numerator == rational.Numerator() && _denominator == rational.Denominator());
	}

	bool operator!= (const Rational& rational) const
	{
		return !(_numerator == rational.Numerator() && _denominator == rational.Denominator());
	}

	bool operator< (const Rational& rational) const
	{
		if (_denominator == rational.Denominator())
		{
			return _numerator < rational.Numerator();
		}

		return (_numerator * rational.Denominator()) < (rational.Numerator() * _denominator);
	}

	bool operator> (const Rational& rational) const
	{
		return rational < *this;
	}

	friend ostream& operator<< (ostream& stream, const Rational& rational)
	{
		stream << rational.Numerator() << "/" << rational.Denominator();

		return stream;
	}

	friend istream& operator>> (istream& stream, Rational& rational)
	{
		if (stream.eof())
			return stream;

		int num = 0, den = 1;
		stream >> num;
		stream.ignore(1);
		stream >> den;
		rational = Rational(num, den);

		return stream;
	}

private:
	int _numerator;
	int _denominator;
};

Rational Operation(const char& oper, const Rational& r1, const Rational& r2)
{
	Rational res;

	if (oper == '+')
	{
		res = r1 + r2;
	}
	else if (oper == '-')
	{
		res = r1 - r2;
	}
	else if (oper == '*')
	{
		res = r1 * r2;
	}
	else if (oper == '/')
	{
		res = r1 / r2;
	}

	return res;
}

int main() {
	try
	{
		Rational r1, r2, result;
		char oper;
		cin >> r1;
		cin.ignore(1);
		cin >> oper;
		cin.ignore(1);
		cin >> r2;

		result = Operation(oper, r1, r2);

		cout << result << endl;
	}
	catch (invalid_argument& ia)
	{
		cout << ia.what() << endl;
	}
	catch (domain_error& de)
	{
		cout << de.what() << endl;
	}

	return 0;
}