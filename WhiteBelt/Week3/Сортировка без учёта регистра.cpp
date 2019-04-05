#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string ToLower(string s)
{
	string temp;
	for (auto a : s)
		temp += tolower(a);

	return temp;
}

int main() {
  vector<string> v;

  int lenth;
  cin >> lenth;

  for (int i = 0; i < lenth; ++i)
  {
	  string s;
	  cin >> s;
	  v.push_back(s);
  }

  sort(begin(v), end(v), [](string s1, string s2){return ToLower(s1) < ToLower(s2);});

  for (const auto a : v)
  {
	  cout << a << " ";
  }

  return 0;
}
