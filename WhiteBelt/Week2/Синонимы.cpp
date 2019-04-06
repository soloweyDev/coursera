#include <set>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	int Q;
	cin >> Q;

	set<set<string>> libr;
	map<string, int> words;

	for (int i = 0; i < Q; i++)
	{
		string S;
		cin >> S;

		if (S == "ADD")
		{
			string b;
			cin >> S >> b;

			long long unsigned int count = libr.size();
			libr.insert({ S, b });

			if (count < libr.size())
			{
				words.count(S) == 0 ? words[S] = 1 : ++words[S];
				words.count(b) == 0 ? words[b] = 1 : ++words[b];
			}
		}

		if (S == "CHECK")
		{
			string b;
			cin >> S >> b;
			if (libr.count({ S, b }) > 0) cout << "YES" << endl;
			else cout << "NO" << endl;
		}

		if (S == "COUNT")
		{
			cin >> S;
			cout << words[S] << endl;
		}
	}
	return 0;
}