#include <iostream>
using namespace std;

#include "student_new.h"

void set( Student & sa, int n);
const int pupils = 3;
const int quizzes = 5;

int main() {
	Student ada[pupils] = {quizzes, quizzes, quizzes};
	int i;
	for(i= 0; i < pupils; i++){
		set(ada[i], quizzes);
	}
		for(i = 0; i < pupils; i++){
			cout << "\n" << ada[i];
			cout << "average: " << ada[i].Average() << "\n";
		}


	return 0;
}
void set(Student& sa, int n){
	cout << "Please enter the students name: ";
	cin >> sa;
	cout << "Please enter " << n << "quiz scores:\n";
	for(int i = 0;  i < n; i++){
		std::cin >> sa[i];
	}
		while(cin.get() != '\n')
			continue;


}
