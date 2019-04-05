#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		history_first_name[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		history_last_name[year] = last_name;
	}
	string GetFullName(int year) {
		_first_name = GetValueHistory(year, history_first_name);
		_last_name = GetValueHistory(year, history_last_name);

		if (_first_name == "" && _last_name == "")
			return "Incognito";
		else if (_first_name == "" && _last_name != "")
			return _last_name + " with unknown first name";
		else if (_first_name != "" && _last_name == "")
			return _first_name + " with unknown last name";

		return _first_name + " " + _last_name;
	}
private:
	map<int, string> history_first_name;
	map<int, string> history_last_name;
	string _first_name;
	string _last_name;
	string GetValueHistory(int year, const map<int, string>& history)
	{
		string result = "";
		int _year = 0;
		for (auto a: history)
		{
			if (a.first <= year)
			{
				if (_year <= a.first)
				{
					result = a.second;
					_year = a.first;
				}
			}
		}

		return result;
	}
};

int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	return 0;
}
