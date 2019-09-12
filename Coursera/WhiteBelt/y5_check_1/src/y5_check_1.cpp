
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Person {
public:
    Person(const string& name, const string& type);

    virtual void Walk(const string& destination) const;
    string Name() const;
    string Type() const;

protected:
    const string name_;
    const string type_;
};

class Student : public Person{
public:
    Student(const string& name, const string& favouriteSong);

    void Learn() const;
    void Walk(const string& destination) const override;
    void SingSong() const;

private:
    const string favouriteSong_;
};


class Teacher : public Person{
public:
    Teacher(const string& name, const string& subject);

    void Teach() const;

private:
    const string subject_;
};


class Policeman : public Person{
public:
    Policeman(const string& name);

    void Check(const Person& p) const;
};



//-----------------Person--------------------//

Person::Person(const string& name, const string& type) : name_(name), type_(type){};

void Person::Walk(const string& destination) const {
    cout << type_ << ": " << name_ << " walks to: " << destination << endl;
}

string Person::Name() const {return name_;}
string Person::Type() const {return type_;}

//-----------------Student--------------------//

Student::Student(const string& name, const string& favouriteSong) :
Person(name, "Student"), favouriteSong_(favouriteSong) {}

void Student::Learn() const {
    cout << type_ << ": " << name_ << " learns" << endl;
}

void Student::Walk(const string& destination) const {
    Person::Walk(destination);
    cout << type_ << ": " << name_ << " sings a song: " << favouriteSong_ << endl;
}

void Student::SingSong() const {
    cout << type_ << ": " << name_ << " sings a song: " << favouriteSong_ << endl;
}


//-----------------Teacher--------------------//

Teacher::Teacher(const string& name, const string& subject) : Person(name, "Teacher"), subject_(subject) {}

void Teacher::Teach() const {
    cout << type_ << ": " << name_ << " teaches: " << subject_ << endl;
}


//-----------------Policeman--------------------//

Policeman::Policeman(const string& name) : Person(name, "Policeman"){}

void Policeman::Check(const Person& p) const {
    cout << type_ << ": " << name_ << " checks " << p.Type() << ". "
    << p.Type() << "'s name is: " << p.Name() << endl;
}



//-----------------main--------------------//

void VisitPlaces(const Person& person, const vector<string>& places) {
    for (const auto& p : places)
        person.Walk(p);
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    vector<string> places {"Moscow", "London"};

    VisitPlaces(t, places);
    p.Check(s);
    VisitPlaces(s, places);
    return 0;
}
