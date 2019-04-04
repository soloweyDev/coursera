#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int NOD(const int a, const int b)
{
	int t1 = a;
	int t2 = b;
	// пока оба числа положительны, будем их уменьшать, не меняя их НОД
	while (t1 > 0 && t2 > 0)
	{
		// возьмём большее из чисел и заменим его остатком от деления на второе
		// действительно, если a и b делятся на x, то a - b и b делятся на x
		// тогда и a % b и b делятся на x, так что можно a заменить на a % b
		if (t1 > t2)
		{
			t1 %= t2;
		}
		else
		{
			t2 %= t1;
		}

	}

	// если одно из чисел оказалось равно нулю, значит, на последней итерации
	// большее число разделилось на меньшее
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

int main() {
	{
		const set<Rational> rs = { { 1, 2 }, { 1, 25 }, { 3, 4 }, { 3, 4 }, { 1, 2 } };
		if (rs.size() != 3) {
			cout << "Wrong amount of items in the set" << endl;
			return 1;
		}

		vector<Rational> v;
		for (auto x : rs) {
			v.push_back(x);
		}
		if (v != vector<Rational>{{1, 25}, { 1, 2 }, { 3, 4 }}) {
			cout << "Rationals comparison works incorrectly" << endl;
			return 2;
		}
	}

	{
		map<Rational, int> count;
		++count[{1, 2}];
		++count[{1, 2}];

		++count[{2, 3}];

		if (count.size() != 2) {
			cout << "Wrong amount of items in the map" << endl;
			return 3;
		}
	}
	cout << "OK" << endl;

	return 0;
}