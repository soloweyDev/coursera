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
        string _first_name = GetValueHistory(year, history_first_name);
        string _last_name  = GetValueHistory(year, history_last_name);

        if (_first_name == "" && _last_name == "")
            return "Incognito";
        else if (_first_name == "" && _last_name != "")
            return _last_name + " with unknown first name";
        else if (_first_name != "" && _last_name == "")
            return _first_name + " with unknown last name";

        return _first_name + " " + _last_name;
    }
    string GetFullNameWithHistory(int year) {
        vector<string> _first_name = GetValueHistoryFull(year, history_first_name);
        vector<string> _last_name  = GetValueHistoryFull(year, history_last_name);

        if (_first_name.size() == 0 && _last_name.size() == 0)
            return "Incognito";
        else if (_first_name.size() == 0 && _last_name.size() != 0)
        {
            return GetStringValue(_last_name) + " with unknown first name";
        }
        else if (_first_name.size() != 0 && _last_name.size() == 0)
        {
            return GetStringValue(_first_name) + " with unknown last name";
        }

        return GetStringValue(_first_name) + " " + GetStringValue(_last_name);
    }
private:
    map<int, string> history_first_name;
    map<int, string> history_last_name;

    string GetValueHistory(int year, const map<int, string>& history)
    {
        string result = "";
        for (auto a : history)
        {
            if (a.first <= year)
            {
                result = a.second;
            }
            else
            {
                break;
            }
        }

        return result;
    }

    vector<string> GetValueHistoryFull(int year, const map<int, string>& history)
    {
        vector<string> result;
        for (auto a : history)
        {
            if (a.first <= year)
            {
                result.push_back(a.second);
            }
            else
            {
                break;
            }
        }

        return result;
    }

    string GetStringValue(const vector<string>& v)
    {
        string temp;

        if (v.size() == 1)
        {
            temp = v[0];
        }
        else
        {
            bool b = false;
            string s;
            for (int i = (v.size() - 1); i >= 0; --i)
            {
                if (i != (v.size() - 1))
                {
                    if (s != v[i])
                    {
                        if (b)
                        {
                            temp += ", " + v[i];
                            s = v[i];
                        }
                        else
                        {
                            temp += " (" + v[i];
                            b = true;
                            s = v[i];
                        }
                    }
                }
                else
                {
                    temp = v[i];
                    s = v[i];
                }
            }
            if (b) temp += ")";
        }

        return temp;
    }
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}
