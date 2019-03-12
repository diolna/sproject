#include <vector>
 #include <iostream>


using namespace std;

template<class It, class T>
struct Row{
	It I;
	T& operator[](size_t index){
		return *next(I, index);
	}
	 T& At(size_t i) {
	    return (*this)[i];
	  }

};

int main() {
	vector<int> v ={1,1,1,3,3,3,4,4,4};
	Row<typename vector<int>::iterator, int> aaa;
	auto it = v.begin();
	aaa.I=v.begin();
	for(int x=0; x<v.size(); ++x){
	cout << "aaa[" << "x" <<"]= " << aaa[x] << endl;
	}
	cout << aaa.At(3) << endl;
	pair p(5, true);

}




