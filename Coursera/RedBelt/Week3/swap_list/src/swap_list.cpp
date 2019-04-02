#include <iostream>
#include <list>

using namespace std;

template <typename T, typename IT>
void SwapListElements(list<T>& lst, IT iterator1,IT iterator2){

	const auto iterator2_next = next(iterator2);
	lst.splice(iterator1, lst, iterator2);
	lst.splice(iterator2_next, lst, iterator1);


}

int main() {

	list<int> list_1 ={3333,4,6,8,12};
	list<int> list_2 = {4444,3,6,2,11};
	auto it = list_1.begin();

	SwapListElements(list_2, list_1.begin(), list_2.begin());
//	list_1.splice(it, list_2);
//
//	list_2.splice(list_1.begin(), list_1, it, list_1.end());

	cout << "list_1 = ";
	for(auto& i: list_1){
		cout << i << " ";
	}
	cout << endl;
	cout << "list_2 = ";
	for(auto& i: list_2){
			cout << i << " ";
		}
	return 0;
}
