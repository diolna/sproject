
#include <iostream>
#include <vector>
using namespace std;

using It = vector<int>:: const_iterator;
using Itt = vector<int>:: iterator;

void PrintVectorPart(const vector<int>& numbers){
	It xxx = begin(numbers);
	vector<int> num ={4,5,6,7};
	Itt ccc = begin(num);
	auto temp = begin(numbers);
	for(auto it = begin(numbers); it!=end(numbers); ++it){
		if(*it<0){

			break;
		}
		++temp;
	}

	while(temp!=begin(numbers)){
		--temp;
		cout << *temp << " ";

	}
	cout << endl;
}

int main() {
	 PrintVectorPart({6, 1, 8, -5, 4});
	  PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
	  PrintVectorPart({6, 1, 8, 5,4});
	return 0;
}
