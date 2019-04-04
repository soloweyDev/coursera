#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
	ifstream input("input.txt");
	if (input)
	{
		double value = 0.0;
		cout << fixed << setprecision(3);
		input >> value;
		cout << value << endl;
		input >> value;
		cout << value << endl;
		input >> value;
		cout << value << endl;
	}
	input.close();

	return 0;
}
