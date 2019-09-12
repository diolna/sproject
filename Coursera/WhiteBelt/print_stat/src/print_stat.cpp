

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

/*
enum class Gender {
  FEMALE,
  MALE
};

struct Person {
  int age;  // возраст
  Gender gender;  // пол
  bool is_employed;  // имеет ли работу
};

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end){
	 if (range_begin == range_end) {
	    return 0;
}
	 vector<typename InputIt::value_type> range_copy(range_begin, range_end);
	  auto middle = begin(range_copy) + range_copy.size() / 2;
	  nth_element(
	      begin(range_copy), middle, end(range_copy),
	      [](const Person& lhs, const Person& rhs) {
	        return lhs.age < rhs.age;
	      }
	  );
	  return middle->age;
	}
*/
void PrintStats(vector<Person> persons){

cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << endl;
auto border = partition(persons.begin(), persons.end(),
				[](Person p){
					return p.gender== Gender::FEMALE;

				}
				);

cout << "Median age for females = " << ComputeMedianAge(persons.begin(), border) << endl;
auto border1 = partition(persons.begin(), persons.end(),
				[](Person p){
					return p.gender== Gender::MALE;

				}
				);

cout << "Median age for males = " << ComputeMedianAge(persons.begin(), border1) << endl;

auto border2 = partition(persons.begin(), persons.end(),
				[](Person p){
					return p.gender== Gender::FEMALE && p.is_employed==1;

				}
				);

cout << "Median age for employed females = " << ComputeMedianAge(persons.begin(), border2) << endl;

auto border3 = partition(persons.begin(), persons.end(),
				[](Person p){
					return p.gender== Gender::FEMALE && p.is_employed==0;

				}
				);

cout << "Median age for unemployed females = " << ComputeMedianAge(persons.begin(), border3) << endl;

auto border4 = partition(persons.begin(), persons.end(),
				[](Person p){
					return p.gender== Gender::MALE && p.is_employed==1;

				}
				);

cout << "Median age for employed males = " << ComputeMedianAge(persons.begin(), border4) << endl;

auto border5 = partition(persons.begin(), persons.end(),
				[](Person p){
					return p.gender== Gender::MALE && p.is_employed==0;

				}
				);

cout << "Median age for unemployed males = " << ComputeMedianAge(persons.begin(), border5) << endl;

}

int main() {
  vector<Person> persons = {
      {31, Gender::MALE, false},
      {40, Gender::FEMALE, true},
      {24, Gender::MALE, true},
      {20, Gender::FEMALE, true},
      {80, Gender::FEMALE, false},
      {78, Gender::MALE, false},
      {10, Gender::FEMALE, false},
      {55, Gender::MALE, true},
  };
  PrintStats(persons);
  return 0;
}
