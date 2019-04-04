#include <iostream>
#include <string>
#include <map>
#include <set>
#include <exception>
#include <iomanip>
#include <sstream>
#include <algorithm>

using namespace std;

class Date
{
public:
	Date(int new_year, int new_month, int new_day)
	{
		year = new_year;
		if (new_month < 1 || new_month > 12)
		{
			string s = "Month value is invalid: " + to_string(new_month);
			throw runtime_error(s);
		}
		month = new_month;
		if (new_day < 1 || new_day > 31)
		{
			string s = "Day value is invalid: " + to_string(new_day);
			throw runtime_error(s);
		}
		day = new_day;
	}
	int GetYear() const
	{
		return year;
	}
	int GetMonth() const
	{
		return month;
	}
	int GetDay() const
	{
		return day;
	}
private:
	int year;
	int month;
	int day;
};

bool operator<(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() == rhs.GetYear())
	{
		if (lhs.GetMonth() == rhs.GetMonth())
		{
			return lhs.GetDay() < rhs.GetDay();
		}

		return lhs.GetMonth() < rhs.GetMonth();
	}

	return lhs.GetYear() < rhs.GetYear();
}

bool operator==(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() != rhs.GetYear())
	{
		if (lhs.GetMonth() != rhs.GetMonth())
		{
			return lhs.GetDay() == rhs.GetDay();
		}

		return true;
	}

	return true;
}

class Database
{
public:
	void AddEvent(const Date& date, const string& event)
	{
		database[date].insert(event);
	}

	bool DeleteEvent(const Date& date, const string& event)
	{
		if (database.count(date) != 0)
		{
			auto& a = database.at(date);
			for (auto str : a)
			{
				if (str == event)
				{
					a.erase(str);

					return true;
				}
			}
		}

		return false;
	}

	int  DeleteDate(const Date& date)
	{
		int count = 0;
		if (database.count(date) != 0)
		{
			auto a = database.at(date);
			count = a.size();
			database.erase(date);
		}

		return count;
	}

	void Find(const Date& date) const
	{
		if (database.count(date) != 0)
		{
			auto a = database.at(date);
			for (auto str : a)
			{
				cout << str << endl;
			}
		}
	}

	void Print() const
	{
		for (const auto& a : database)
		{
			for (const auto& str : a.second)
			{
				cout << fixed << setfill('0')
					<< setw(4) << a.first.GetYear() << "-"
					<< setw(2) << a.first.GetMonth() << "-"
					<< setw(2) << a.first.GetDay() << " "
					<< str << endl;
			}
		}
	}
private:
	map<Date, set<string>> database;
};

Date SetDate(const string& date)
{
	stringstream new_ss(date);

	int year = -1, month = 0, day = 0;

	new_ss >> year;
	if (new_ss.peek() != '-')
	{
		string s = "Wrong date format: " + date;
		throw runtime_error(s);
	}
	new_ss.ignore(1);
	if (new_ss.peek() != '-' && !(new_ss.peek() >= '0' && new_ss.peek() <= '9') && new_ss.peek() != '+')
	{
		string s = "Wrong date format: " + date;
		throw runtime_error(s);
	}
	if (new_ss.peek() == '-' && !(new_ss.peek() >= '0' && new_ss.peek() <= '9'))
	{
		new_ss.ignore(1);
		if (!(new_ss.peek() >= '0' && new_ss.peek() <= '9'))
		{
			string s = "Wrong date format: " + date;
			throw runtime_error(s);
		}

		new_ss >> month;
		month = -month;
	}
	else
	{
		new_ss >> month;
	}
	if (new_ss.peek() != '-')
	{
		string s = "Wrong date format: " + date;
		throw runtime_error(s);
	}
	new_ss.ignore(1);
	if (new_ss.peek() != '-' && !(new_ss.peek() >= '0' && new_ss.peek() <= '9') && new_ss.peek() != '+')
	{
		string s = "Wrong date format: " + date;
		throw runtime_error(s);
	}
	if (new_ss.peek() == '-')
	{
		new_ss.ignore(1);
		if (!(new_ss.peek() >= '0' && new_ss.peek() <= '9'))
		{
			string s = "Wrong date format: " + date;
			throw runtime_error(s);
		}

		new_ss >> day;
		day = -day;
	}
	else
	{
		new_ss >> day;
	}
	if (new_ss.peek() != EOF)
	{
		string s = "Wrong date format: " + date;
		throw runtime_error(s);
	}

	return{ year, month, day };
}

int main() {
	Database db;

	string command;
	while (getline(cin, command))
	{
		if (command.size() == 0) continue;

		try
		{
			stringstream ss(command);
			ss >> command;
			string date;
			ss >> date;

			if (command == "Add")
			{
				string event;
				ss.ignore(1);
				ss >> event;

				if (event.empty())
				{
					continue;
				}
				Date d = SetDate(date);

				db.AddEvent(d, event);
			}
			else if (command == "Del")
			{
				Date d = SetDate(date);

				if (ss.eof())
				{
					cout << "Deleted " << db.DeleteDate(d) << " events" << endl;
				}
				else
				{
					string event;
					ss.ignore(1);
					ss >> event;

					if (db.DeleteEvent(d, event))
					{
						cout << "Deleted successfully" << endl;
					}
					else
					{
						cout << "Event not found" << endl;
					}
				}
			}
			else if (command == "Find")
			{
				db.Find(SetDate(date));
			}
			else if (command == "Print")
			{
				db.Print();
			}
			else
			{
				cout << "Unknown command: " + command << endl;
			}
		}
		catch (exception& ex)
		{
			cout << ex.what() << endl;
			//return -1;
		}
	}

	return 0;
}