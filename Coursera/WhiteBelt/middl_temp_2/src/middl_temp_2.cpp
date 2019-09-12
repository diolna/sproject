#include <iostream>
#include <vector>
#include <limits>

using namespace std;


int64_t FunkAverageArifmetic(const vector<int64_t>& Temperature_of_Days){
	int64_t Average = 0;
	for(auto i: Temperature_of_Days){
		Average +=i;

	}
	return Average /=static_cast<int64_t>(Temperature_of_Days.size());
}

vector<int64_t> FindNumberStringOutOfRange(const vector<int64_t>& vec,  const int64_t& range ){

				    vector<int64_t> Out_Of_Range;
				    int32_t n=0;
	           		for(auto i: vec){

	           			if(i> range) {
	           				Out_Of_Range.push_back(n);
	           				++n;
	           			}else {
	           				++n;
	           			}

				}


	return Out_Of_Range;

}

void FunkPrintVector(const vector<int64_t>& v){
	for(auto i: v){
		cout << i << " ";
	}
}



int main() {

	//cout << numeric_limits<int>::max() << numeric_limits<int>::min()
	//		<<"max size_t =" <<  numeric_limits<size_t>:: max() << "min = "<<  numeric_limits<size_t>::min()<< endl;
	uint32_t Number_Day;
	int64_t Temperature;
	vector<int64_t> Vector_Day, result;

	//cout << "Enter number days " << endl;
	cin >> Number_Day;
	for(uint32_t i=0; i<=Number_Day-1; ++i){
		//cout << "Enter temperature " << i+1 << " Day" << endl;
		cin >> Temperature;
		Vector_Day.push_back(Temperature);
	}

	//cout << "middll arif " << FunkAverageArifmetic(Vector_Day) << endl;
	 result =FindNumberStringOutOfRange(Vector_Day, FunkAverageArifmetic(Vector_Day));
	 cout << result.size() << endl;

	 FunkPrintVector(result);

	return 0;
}
