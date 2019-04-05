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

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}