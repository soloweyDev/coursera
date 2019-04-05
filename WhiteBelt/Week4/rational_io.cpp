#include <iostream>
#include <sstream>
#include <istream>

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

private:
  int _numerator;
  int _denominator;
};

Rational operator+ (const Rational& lhs, const Rational& rhs)
{
	return Rational((lhs.Numerator() * rhs.Denominator()) + (rhs.Numerator() * lhs.Denominator()), lhs.Denominator() * rhs.Denominator());
}

Rational operator- (const Rational& lhs, const Rational& rhs)
{
	return Rational((lhs.Numerator() * rhs.Denominator()) - (rhs.Numerator() * lhs.Denominator()), lhs.Denominator() * rhs.Denominator());
}

bool operator== (const Rational& lhs, const Rational& rhs)
{
	return (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator());
}

ostream& operator<< (ostream& stream, const Rational& rational)
{
	if (stream)
	{
		stream << rational.Numerator() << "/" << rational.Denominator();
	}

	return stream;
}

istream& operator>> (istream& stream, Rational& rational)
{
	if (stream.tellg() == -1)
	{
		return stream;
	}
	int num = rational.Numerator(), den = rational.Denominator();
	stream >> num;
	stream.ignore(1);
	stream >> den;

	rational = Rational(num, den);

	return stream;
}

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    {
            istringstream input("");
            Rational r;
            input >> r;
            bool equal = r == Rational(5, 7);
            if (!equal) {
                cout << "5/7 is incorrectly read as " << r << endl;
                return 2;
            }
        }

    cout << "OK" << endl;
    return 0;
}
