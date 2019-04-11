#include <iostream>
#include <vector>

using namespace std;

int main() {
	int count = 0;
	cin >> count;

	vector<float> data;
	float temperature = 0.0, total = 0.0;
	for (int i = 0; i < count; ++i)
	{
		cin >> temperature;
		data.push_back(temperature);
		total += temperature;
	}

	float average = total / count;
	int num = 0;
	vector<int> index;
	for (int i = 0; i < count; ++i)
	{
		if (data[i] > average)
		{
			index.push_back(i);
			num++;
		}
	}

	cout << num << endl;
	for (auto a : index)
	{
		cout << a << " ";
	}

	return 0;
}
