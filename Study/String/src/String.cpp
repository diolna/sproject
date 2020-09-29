#include <iostream>
#include "string.h"

const int ArSize = 10;
const int MaxLen = 81;

int main() {

String name;
std::cout << "Hi, whats your name?\n";
std::cin >> name;
std::cout << name << ", please enter up to " << ArSize << "short sayings <empty line to quit>:\n";

String sayings[ArSize];
char temp[MaxLen];
int i;
for(i =0; i < ArSize; i++){
	std::cout << i + 1 << ": ";
	std::cin.get(temp, MaxLen);                   // read MaxLen-1 symbol from stream. end symbol = '\0'
	while(std::cin && std::cin.get() !='\n')      // if your enter > MaxLen symbol => this symbols have steram.
		continue;									// this read all symbols while != '\n' clear stream.
	if(!std::cin || temp[0] == '\0')                 // check error or empty line
		break;
	else
		sayings[i] = temp;
}
int total = i;

std::cout << "Here are your sayings:\n";
for(i = 0; i < total; i ++)
	std::cout << sayings[i] << "\n";

int shortest = 0;
int first = 0;
for(i = 1; i < total; i++){
	if(sayings[i].lenght() < sayings[shortest].lenght())
		shortest = i;
	if(sayings[i] < sayings[first])
		first = 1;
}

std::cout << "Shortest saying:\n" << sayings[shortest] << "\n";
std::cout << "First alphabetically:\n" << sayings[first] << "\n";
std::cout << "This program used " << String::HowMany() << " String objects. Bye.\n";




	return 0;
}

