
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "String.h"

const int ArSize = 10;
const int MaxLen = 81;



int main() {


String name;
std::cout << "Hi, what`s your name&\n";
std::cin >> name;
std::cout << name << ", please enter up to " << ArSize
		<< " short sayings <empty line to quite>:\n";
String sayings[ArSize];
char temp[MaxLen];
int i;
for(i = 0; i <ArSize; i++){
	std::cout << i+1 << ": ";
	std::cin.get(temp, MaxLen);
	while(std::cin && std::cin.get() != '\n')
		continue;
	if(!std::cin || temp[0] == '\0')
		break;
	else
		sayings[i] = temp;
}
int total = i;

std::cout << "Here are your sayings:\n";
for(i = 0; i < total; i++){
	std::cout << sayings[i] << "\n";
}

String* shortest = &sayings[0];
String* first = &sayings[0];
for(i = 1; i < total; i++){
	if(sayings[i].lenght() < shortest->lenght())
		shortest = &sayings[i];
	if(sayings[i] < *first)
		first = &sayings[i];

}

std::cout << "Shortest sayings:\n" << *shortest << "\n";
std::cout << "First alphabetically:\n" << *first << "\n";

srand(time(0));
int choice = rand()% total;
String *favorite = new String(sayings[choice]);
std::cout << "My favorite saying:\n" << *favorite <<"\n";
delete favorite;
std::cout << "Bye.\n";

	return 0;
}
