
#include <iostream>
#include <vector>
#include <bitset>
#include <string>

using namespace std;

template <typename String>
using Group = vector<String>;

template <typename String>
vector<char> ParseString(String st){
				vector<char> v;
				for(auto& i : st){
					v.push_back(i);
				}
				return v;
}


template <typename String>
vector<Group<String>> GroupHeavyStrings(vector<String> strings){
						int temp =0;
						vector<Group<String>> v;
						Group<String> g;
						for(auto it = strings.begin(); it!= strings.end(); ++it){
							g.clear();
							vector<char> pars = ParseString(*it);
							for(auto it= strings.begin(); it!=strings.end(); ++it) {
								for(auto i : pars) {
									for(int n=0; n<(*it).size(); ++n){
										size_t pos =(*it).find_first_of(i);
										if(pos == std::string::npos) temp =1;
									}
									if(temp ==0 ) g.push_back(*it);
									temp =0;
								}
							}

						v.push_back(g);
						}
						return v;
}

//ostream& operator<<(Group<String> rhs){

//}


int main() {

	vector<string> v = {"law", "port", "top", "laptop", "pot", "paloalto", "wall", "awl"};
	for(auto& i : GroupHeavyStrings(v)){
		for(auto& n : i) {
			cout << n << " ";//cout << "Group string = " << i << " ";
		}
		cout << endl;
	}

	return 0;
}
