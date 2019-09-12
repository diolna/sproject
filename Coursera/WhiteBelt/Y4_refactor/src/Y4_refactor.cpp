#include <iostream>
#include <string>
#include <vector>


using namespace std;

class People {
public:
	People(const string& name, const string& profession): name_(name), profession_(profession){}
	virtual void Walk(const string& destination) const   {
	        cout << this->profession_ <<": " << this->name_ << " walks to: " << destination << endl;
	    }
	const string GetName()const { return name_;}
	const string GetProfession() const {return profession_;}

private:
	const string name_;
	const string profession_;
};


class Student: public People {
public:

    Student(const string& name, const string& favouriteSong): People(name, "Student"), FavouriteSong(favouriteSong) {}

    void Learn() const {
        cout << "Student: " << GetName() << " learns" << endl;
    }

    void Walk(const string& destination) const override {
    	 People::Walk(destination);
         cout << "Student: " << GetName() << " sings a song: " << FavouriteSong << endl;
    }

    void SingSong() const {
        cout << "Student: " << GetName() << " sings a song: " << FavouriteSong << endl;
    }

private:
     const string FavouriteSong;

};


class Teacher: public People{
public:

    Teacher(const string& name, const string& subject) : People(name, "Teacher"), Subject(subject){}

    void Teach() const {
        cout << "Teacher: " <<GetName() << " teaches: " << Subject << endl;
    }
private:
    const string Subject;

};


class Policeman : public People{
public:
    Policeman(const string& name): People(name, "Policeman") {}

    void Check(const People& p) const {
    	cout << GetProfession()  << ": " << GetName() << " checks " << p.GetProfession()<< ". " <<
    			p.GetProfession() << "'s name is: " << p.GetName() << endl;

    }
};


void VisitPlaces(const People& people, const vector<string>& places) {

    for (const auto& p : places) {
        people.Walk(p);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
