#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Student {
	string first_name;
	string last_name;
	int day;
	int month;
	int year;
};

vector<Student> SetStudents()
{
	int line = 0;
	cin >> line;

	vector<Student> students;
	for (int i = 0; i < line; ++i)
	{
		Student student;
		cin >> student.first_name;
		cin >> student.last_name;
		cin >> student.day;
		cin >> student.month;
		cin >> student.year;
		students.push_back(student);
	}

	return students;
}

void Requests(const vector<Student>& students)
{
	int line = 0;
	cin >> line;

	for (int i = 0; i < line; ++i)
	{
		string request;
		cin >> request;

		int num;
		cin >> num;

		if (request == "name" && (num - 1) >= 0 && (num - 1) < students.size())
		{
			cout << students[num - 1].first_name << " " << students[num - 1].last_name << endl;
		}
		else if (request == "date" && (num - 1) >= 0 && (num - 1) < students.size())
		{
			cout << students[num - 1].day << "." << students[num - 1].month << "." << students[num - 1].year << endl;
		}
		else
		{
			cout << "bad request" << endl;
		}
	}
}

int main() {
	vector<Student> students = SetStudents();
	Requests(students);

	return 0;
}