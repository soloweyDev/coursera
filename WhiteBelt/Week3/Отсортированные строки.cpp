class SortedStrings {
public:
	void AddString(const string& s) {
		strings.push_back(s);
		sort(begin(strings), end(strings));
	}
	vector<string> GetSortedStrings() {
		return strings;
	}
private:
	vector<string> strings;
};