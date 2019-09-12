class SortedStrings {
public:
	void AddString(const string& st) {
		str.push_back(st);
	}
	vector<string> GetSortedStrings() {
		return Sort(str);
	}
private:

	vector<string> str;
	vector<string> Sort( vector<string>& s) {
		 sort(begin(s), end(s));
		 return s;

	}
};
