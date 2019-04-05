#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class ReversibleString {
public:
	ReversibleString()
	{
		str = "";
	}
	ReversibleString(string s)
	{
		str = s;
	}
	void Reverse()
	{
		reverse(begin(str), end(str));
	}
	string ToString() const
	{
		return str;
	}
private:
	string str;
};

int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;

  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;

  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;

  return 0;
}
