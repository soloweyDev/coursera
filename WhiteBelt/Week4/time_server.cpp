﻿#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() {
	/* Для тестирования повставляйте сюда код, реализующий различное поведение этой функии:
	* нормальный возврат строкового значения
	* выброс исключения system_error
	* выброс другого исключения с сообщением.
	*/
	if (true)
	{
		throw invalid_argument("test exception invalid_argument");
		//throw system_error(EDOM, generic_category(), "hello world");
	}

	return "10:20:30";
}

class TimeServer {
public:
	string GetCurrentTime() {
		/* Реализуйте этот метод:
		* если AskTimeServer() вернула значение, запишите его в LastFetchedTime и верните
		* если AskTimeServer() бросила исключение system_error, верните текущее значение
		поля LastFetchedTime
		* если AskTimeServer() бросила другое исключение, пробросьте его дальше.
		*/

		try
		{
			LastFetchedTime = AskTimeServer();
		}
		catch (const system_error& er)
		{ }

		return LastFetchedTime;
	}

private:
	string LastFetchedTime = "00:00:00";
};

int main() {
	// Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
	TimeServer ts;
	try {
		cout << ts.GetCurrentTime() << endl;
	}
	catch (const exception& e) {
		cout << "Exception got: " << e.what() << endl;
	}
	return 0;
}