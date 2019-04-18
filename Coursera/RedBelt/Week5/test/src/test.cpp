
#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

template <typename String>
using Group = vector<String>;

template <typename String>
using Char = typename String::value_type;

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

						vector<Group<String>> v;
						Group<String> g;
						size_t pos = 0;
						size_t current_pos = 0;
						bool flag_if_not = false;
						for(auto it = strings.begin(); it!= strings.end(); ++it){

							 g.clear();
							 if(!((*it).empty())){
							 g.push_back(*it);
							 }
							current_pos = pos + 1;
							while( current_pos != pos) {


								if(current_pos == strings.size()) {
//									current_pos =0;
									break;
								}
//								if(current_pos == pos) {
//									break;
//								}

								for(auto it_char : *(strings.begin() + current_pos)) {

//									if((*it).find_first_of(it_char)== std::string::npos	) {
//									auto symb = *it;
//									auto it1 = std::find(symb.begin(), symb.end(), it_char);
									if(std::find((*it).begin(), (*it).end(), it_char) == (*it).end()){
										flag_if_not = true;
									}
								}
								for(auto it_char : *(it)) {
//									if((*(strings.begin() + current_pos)).
////										find_first_of(it_char)== std::string::npos	) {
//								  auto symb = *(strings.begin() + current_pos);
//
//									auto it = std::find(symb.begin(), symb.end(), it_char);
									if(std::find((*(strings.begin() + current_pos)).begin()
												, (*(strings.begin() + current_pos)).end()
												, it_char)== (*(strings.begin() + current_pos)).end()){
											flag_if_not = true;
											}
								}

//								cout << endl;
								if(flag_if_not == false) {
									if(!((*(strings.begin() + current_pos)).empty())){

									g.push_back(move(*(strings.begin() + current_pos)));
									}
									}


								flag_if_not = false;
								++current_pos;
							}
							++pos;
							if(!(g.empty())){
							v.push_back(g);
							}
						}
						return v;
}



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
