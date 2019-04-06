#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<int> year = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int month = 0;
	vector<vector<string>> works(year[month]);

	int lenth;
	cin >> lenth;

	for (int i = 0; i < lenth; ++i)
	{
		string command;
		cin >> command;

		if (command == "NEXT")
		{
			vector<vector<string>> temp;
			int newMonth = (month + 1) == 12 ? 0 : month + 1;
			if (year[month] > year[newMonth])
			{
				temp.resize(year[newMonth]);
				for (int i = 0; i < year[newMonth]; ++i)
				{
					temp[i] = works[i];
				}

				int day = year[newMonth] - 1;
				for (int i = day + 1; i < year[month]; ++i)
				{
					for (auto item : works[i])
						temp[day].push_back(item);
				}
			}
			else if (year[month] < year[newMonth])
			{
				temp.insert(end(temp), begin(works), end(works));
				temp.resize(year[newMonth]);
			}
			else
			{
				temp = works;
			}

			month = newMonth;
			works = temp;
		}
		else if (command == "DUMP")
		{
			int day;
			cin >> day;

			if (works[day - 1].size() != 0)
			{
				cout << works[day - 1].size() << " ";
				for (auto item : works[day - 1])
				{
					cout << item << " ";
				}
				cout << endl;
			}
			else
				cout << 0 << endl;
		}
		else if (command == "ADD")
		{
			int day;
			cin >> day;
			string work;
			cin >> work;

			works[day - 1].push_back(work);
		}
	}

	return 0;
}
