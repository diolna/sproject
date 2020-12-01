#include "arraydb.h"
#include <iostream>

ArrayDb::ArrayDb() {
	arr = NULL;
	size = 0;
}

ArrayDb::ArrayDb(unsigned int z, double val){
	size = z;
	arr = new double[z];

	for(unsigned int i = 0; i < size; i++){
		arr[i] = val;
	}
}

ArrayDb::ArrayDb(const double* n, unsigned int s){
	arr = new double [s];
	size = s;
	for(unsigned int i = 0; i < size ; i++){
		arr[i] = n[i];
	}
}
ArrayDb::ArrayDb(const ArrayDb& a){

	arr = new double[a.size];
	size = a.size;
	for(unsigned int i = 0; i < size; i++){
		arr[i] = a.arr[i];
	}
}

double ArrayDb::Average() const{
	double av=0;
	int i;
	for(unsigned int i = 0; i < this->size; i++){
		av +=arr[i];
	}
	if(i >0)
	return av/size;
	else
	{
		std::cerr << "No entries in score array\n";
		return 0;
	}
}
ArrayDb::~ArrayDb(){
	delete [] arr;
}
ArrayDb& ArrayDb::operator =(const ArrayDb& a){
	if(this == &a) return *this;
	delete []arr;
	arr = new double[a.size];
	size = a.size;
	for(unsigned int i = 0; i < size; i++){
		arr[i] = a.arr[i];
	}
	return *this;

}

double& ArrayDb::operator [](int i){
	if(i > size || i < 0) {
		std::cerr << "index out of range\n";
		exit(1);
	}
	return arr[i];
}
const double& ArrayDb::operator [](int i) const {
	if(i >= size || i < 0) {
		std::cerr << "index out of range\n";
		exit(1);
	}
	return arr[i];
}
std::ostream& operator<<(std::ostream& os, const ArrayDb& a){
	int i = 0;
	for( i; i < a.size; i++){
	os << a.arr[i] << " ";
	if(i%5 ==4 ) os << "\n";
	}
	if(i%5 !=0)
		os << "\n";

	return os;
}

