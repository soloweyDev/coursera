#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
	ifstream input("input.txt");
	if (input)
	{
		int line = 0;
		int column = 0;

		input >> line;
		input.ignore(1);
		input >> column;
		input.ignore(1);

		for (int i = 0; i < line; ++i)
		{
			int value;
			cout << fixed;
			for (int j = 0; j < column; ++j)
			{
				input >> value;
				input.ignore(1);
				if (j == (column - 1))
				{
					cout << setw(10) << value;
				}
				else
				{
					cout << setw(10) << value << " ";
				}
			}
			cout << endl;
		}
	}
	input.close();

	return 0;
}
