#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human {
public:
	Human(const string& name, const string& type):
		name_(name), type_(type) {
	}

	virtual void Walk(const string& destination) const {
		cout << type_ << ": " << name_ << " walks to: "
		     << destination << endl;
	}

	string GetName() const {
		return name_;
	}

	string GetType() const {
		return type_;
	}

protected:
	const string name_;
	const string type_;
};


class Student : public Human{
public:
	Student(const string& name, const string& favouriteSong):
		Human(name, "Student"), favouriteSong_(favouriteSong) {
	}

	void Learn() const {
		cout << type_ << ": " << name_ << " learns" << endl;
	}

	virtual void Walk(const string& destination) const override {
		Human::Walk(destination);
		SingSong();
	}

	void SingSong() const {
		cout << type_ << ": " << name_ << " sings a song: "
		     << favouriteSong_ << endl;
	}

public:
	const string favouriteSong_;
};


class Teacher : public Human {
public:
	Teacher(const string& name, const string& subject):
		Human(name, "Teacher"), subject_(subject) {
	}

	void Teach() const {
		cout << type_ << ": " << name_ << " teaches: "
		     << subject_ << endl;
	}

public:
	const string subject_;
};


class Policeman : public Human {
public:
	Policeman(const string& name) : Human(name, "Policeman") {
	}

	void Check(Human& h) const {
		cout << type_ << ": " << name_ << " checks " << h.GetType()
		     << ". " << h.GetType() << "'s name is: "
		     << h.GetName() << endl;
	}
};


void VisitPlaces(Human& h, const vector<string>& places) {
	for (auto p : places) {
		h.Walk(p);
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

