bool operator==(const Region& lhs, const Region& rhs){
	tuple<string, string, map<Lang, string>, int64_t> lhs_region(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population);
	tuple<string, string, map<Lang, string>, int64_t> rhs_region(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
	return lhs_region == rhs_region;


}


int FindMaxRepetitionCount(const vector<Region>& regions){
		if(regions.size()==0){return 0;}
//
		int num=1;
		int i =1;
		while(i < static_cast<int>(regions.size())){
				//cout << "i =" << i << endl;
				int num_temp =0;
				int y =0;
				while(y<static_cast<int>(regions.size())){
				//	cout << "i = " << i << "y = " << y << endl;
				if(regions.at(i)==regions.at(y)){++num_temp;}
				++y;
				}
			if(num_temp>num){num=num_temp;}
			++i;
		}
		return num;
}