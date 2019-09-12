
#include <iostream>
#include <vector>
#include <limits>
#include <cstdint>

using namespace std;

uint64_t SumMussBlock(vector<uint64_t>& b){
	uint64_t s= 0;
	for(auto i: b){
		s+=i;
	}
	return s;
}

int main() {

vector<uint64_t> blocks_mass;
uint64_t num_block;
uint64_t density_block;
uint64_t w,h,d;
uint64_t mass;
cin>> num_block;
cin>> density_block;

for(uint64_t i=0; i < num_block; ++i){
	cin >> w >> h >> d;
	mass=w*h*d*density_block;


	blocks_mass.push_back(mass);
}
cout << SumMussBlock(blocks_mass)<< endl;
	return 0;
}
