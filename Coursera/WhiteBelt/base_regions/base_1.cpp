

bool operator<(const Region& lhs, const Region& rhs){
	tuple<string, string, map<Lang, string>, int64_t> lhs_region(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population);
	tuple<string, string, map<Lang, string>, int64_t> rhs_region(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
	return lhs_region < rhs_region;


}



int FindMaxRepetitionCount(const vector<Region>& regions){
		if(regions.size()==0){return 0;}
		//cout << "begin"<< endl;
		map< Region,int> m;
		for(auto& i: regions){
		++m[i];
		//cout << m.at(i)<< endl;
		}
		int n=0;
		for(auto& i: m){
			if(i.second > n){ n= i.second;}
		}
		return n;
}
