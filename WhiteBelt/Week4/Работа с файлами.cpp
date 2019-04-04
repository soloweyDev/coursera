#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	ifstream input("input.txt");
	if (input)
	{
		string line;
		while(getline(input, line))
		{
			cout << line << endl;
		}
	}
	input.close();

	ifstream input2("input.txt");
	ofstream ounput2("output.txt");
	if (input2)
	{
		string line;
		while(getline(input2, line))
		{
			ounput2 << line << endl;
		}
	}
	ounput2.close();
	input2.close();

	return 0;
}
