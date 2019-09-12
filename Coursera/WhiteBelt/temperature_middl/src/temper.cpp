
#include <iostream>
#include <vector>

using namespace std;


int FunkAverageArifmetic(const vector<int>& Temperature_of_Days){
	int Average = 0;
	for(auto i: Temperature_of_Days){
		Average +=i;
	}
	return Average /=Temperature_of_Days.size();
}

vector<int> FindNumberStringOutOfRange(const vector<int>& vec,  const int& range ){

				    vector<int> Out_Of_Range;
				    int n=0;
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

void FunkPrintVector(const vector<int>& v){
	for(auto i: v){
		cout << i << " ";
	}
}



int main() {
	int Number_Day, Temperature;
	vector<int> Vector_Day, result;

	//cout << "Enter number days " << endl;
	cin >> Number_Day;
	for(int i=0; i<=Number_Day-1; ++i){
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
