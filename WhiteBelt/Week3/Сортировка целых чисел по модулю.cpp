#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void Print(const vector<int> v)
{
	for (const auto a : v)
	{
		cout << a << " ";
	}
}

bool F(int a, int b)
{
	if (a < 0) a = -a;
	if (b < 0) b = -b;

	return a < b;
}

int main() {
  vector<int> v;

  int lenth;
  cin >> lenth;

  for (int i = 0; i < lenth; ++i)
  {
	  int num;
	  cin >> num;
	  v.push_back(num);
  }

  sort(begin(v), end(v), F);

  Print(v);

  return 0;
}
