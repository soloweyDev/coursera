#include <iostream>
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

private:
  int _numerator;
  int _denominator;
};

int main() {
  {
    const Rational r(3, 10);
    if (r.Numerator() != 3 || r.Denominator() != 10) {
      cout << "Rational(3, 10) != 3/10" << endl;
      return 1;
    }
  }

  {
    const Rational r(8, 12);
    if (r.Numerator() != 2 || r.Denominator() != 3) {
      cout << "Rational(8, 12) != 2/3" << endl;
      return 2;
    }
  }

  {
    const Rational r(-4, 6);
    if (r.Numerator() != -2 || r.Denominator() != 3) {
      cout << "Rational(-4, 6) != -2/3" << endl;
      return 3;
    }
  }

  {
    const Rational r(4, -6);
    if (r.Numerator() != -2 || r.Denominator() != 3) {
      cout << "Rational(4, -6) != -2/3" << endl;
      return 3;
    }
  }

  {
    const Rational r(0, 15);
    if (r.Numerator() != 0 || r.Denominator() != 1) {
      cout << "Rational(0, 15) != 0/1" << endl;
      return 4;
    }
  }

  {
    const Rational defaultConstructed;
    if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
      cout << "Rational() != 0/1" << endl;
      return 5;
    }
  }

  {
    const Rational r(-2, -3);
    if (r.Numerator() != 2 || r.Denominator() != 3) {
      cout << "Rational(-2, -3) != 2/3" << endl;
      return 5;
    }
  }

  cout << "OK" << endl;
  return 0;
}
