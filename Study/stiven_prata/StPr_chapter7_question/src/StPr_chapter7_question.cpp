//============================================================================
// Name        : StPr_chapter7_question.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "algorithm"
#include "cstring"

using namespace std;

void Func( int *arr_begin, int *arr_end, int value);
double Func_max(const double arr[], int size);
int replace(char *str, char c1, char c2);

int main() {
	int arr[10]= {1,1,1,1,1,1,1,1,1,1};
	int *arr_begin = arr+3;

	// time block
//	int x = 4;
//	int *y = &x;
//	cout << "Value x= " << x << " pointer y = " << y << " Value in pointer *y =" << *y << endl;
// 	//int p = &arr_begin;
//	arr[0] = 555;
//	cout << &arr_begin << endl;
	//cout << p << endl;
	// end time block
	int *arr_end = arr + 8;
	Func( arr_begin, arr_end, 5);
	for(int i=0; i< 10; i++){
		cout << arr[i]<< ",";
	}
	cout << endl;
	double arr_max[5] = {3.2323, 453.21, 44.0908, 43.3,30033.23};
	for(int i= 0; i < 5; i++){
		cout << "array double = " << arr_max[i];
	}
	cout << endl;
	cout << Func_max(arr_max, 5) << endl;
	double *begin_arr = arr_max;
	double *end_arr = arr_max+5;

	cout << "Max element with algorithm " << *max_element(begin_arr, end_arr) << endl;

	char str[4] = {'a','b','c','\0'};
	char * str1= "ABC";
	char str2[34] =  "DEF";
	cout << str << " " << str1 <<" " << str2 << endl;
	char aaa[5] = "dgdr";
	cout <<"input text " << aaa << "     Replace " <<
	  replace(aaa, 'd','f') << "  element " << aaa << endl;

	char p = *"dfdfdf";
	char h = "taco"[2];
	cout << p << " " << h << endl;

	return 0;
}

void Func(int *arr_begin, int *arr_end, int value){

		for(int i = 0; i < arr_end - arr_begin; i++){
		*(arr_begin + i) = value;
		}
}
double Func_max(const double arr[], int size){
	double temp= arr[0];
	for(int i=0; i<size; ++i){
		if(i+1 == size) return temp;
		if(temp < arr[i+1])	temp = arr[i+1];

				}

	return temp;
}

int replace(char * str, char c1, char c2){

		int num =0;
		for(int i=0; i < strlen(str); i++){
			if(str[i] == c1){
				str[i] = c2;
				num++;
			}

		}
		return num;
}


