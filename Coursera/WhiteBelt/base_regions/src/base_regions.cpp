

#include <iostream>
#include <string>
#include<map>
#include<vector>
#include<tuple>


using namespace std;

enum class Lang {
  DE, FR, IT
};

struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};
/*
bool operator==(const Region& lhs, const Region& rhs){
	tuple<string, string, map<Lang, string>, int64_t> lhs_region(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population);
	tuple<string, string, map<Lang, string>, int64_t> rhs_region(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
	return lhs_region == rhs_region;


}
*/
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
/*
int FindMaxRepetitionCount(const vector<Region>& regions){
		map<Region, int> m;
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
*/
/*
int FindMaxRepetitionCount(const vector<Region>& regions){

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
*/
		/*
		int num =1;

		for(int element=0; element<regions.size(); ++element){
			int temp_num =1;
			for(int i= regions.size()-1; i>=element+1; --i ){
				if(regions[element]==regions[i]){

				++temp_num;
				}
				//cout << "element " << element << "cmp with element "<< i << "  value = " << temp_num<< endl;
			}

			if(temp_num>num){num=temp_num;}
	}
	return num;

}
*/

int main() {

  cout << FindMaxRepetitionCount({
      {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      },
  }) << endl;

  cout << FindMaxRepetitionCount({
      {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Toulouse",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          31
      },
  }) << endl;

  return 0;
}
