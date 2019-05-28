#include <iostream>
#include <vector>
#include <map>

bool operator<(const Region& lhs, const Region& rhs) {
	return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
		tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions)
{
	int res = 0;
	if (regions.size() == 0)
		return 0;

	map<Region, int> repetion_count;
	for (int i = 0; i < regions.size(); ++i)
	{
		res = max(res, ++repetion_count[regions[i]]);
	}

	return res;
}