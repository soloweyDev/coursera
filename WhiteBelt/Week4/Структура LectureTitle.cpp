#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Specialization
{
	string value;
	explicit Specialization(string new_specialization)
	{
		value = new_specialization;
	}
};

struct Course
{
	string value;
	explicit Course(string new_course)
	{
		value = new_course;
	}
};

struct Week
{
	string value;
	explicit Week(string new_week)
	{
		value = new_week;
	}
};

struct LectureTitle {
	string specialization;
	string course;
	string week;
	LectureTitle(Specialization new_specialization, Course new_course, Week new_week)
	{
		specialization = new_specialization.value;
		course = new_course.value;
		week = new_week.value;
	}
};
