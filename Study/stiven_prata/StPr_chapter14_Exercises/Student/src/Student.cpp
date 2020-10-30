

#include <iostream>
#include "Student.h"
using namespace std;

void set(Student& sa, int n);

const int pupils = 3;
const int quizzes = 5;

int main() {

Student ada[pupils] = {quizzes, quizzes, quizzes};
int i;
for(i = 0; i <pupils; i++)
		set(ada[i], quizzes);
for(i =0;  i< pupils; i++){
	std::cout << "\n" << ada[i];
	std::cout << "avarage: " << ada[i].Avarage() << "\n";
}

	return 0;
}

void set(Student& sa, int n){
	std::cout << "Please enter the students name: ";
	std::cin >> sa;
	std::cout << "Please enter " << n << "quiz scores:\n";
	for(int i = 0;  i < n; i++)
		std::cin >> sa[i];
		while(cin.get() != "\n")
			continue;

}
