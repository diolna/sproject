#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Citizen {
public:
    Citizen(const string& name, const string& type): Name(name), Type(type) {}

    virtual void Walk(const string& destination) const {
        cout << Type << ": " << Name << " walks to: " << destination << endl;
    }

public:
    const string Name;
    const string Type;
};


class Student : public Citizen {
public:

    Student(const string& name, const string& favouriteSong) : Citizen(name, "Student"),
                                                               FavouriteSong_(favouriteSong) {}

    void Learn() const {
        cout << Type << ": " << Name << " learns" << endl;
    }

    void SingSong() const {
        cout << Type << ": " << Name << " sings a song: " << FavouriteSong_ << endl;
    }

    void Walk(const string& destination) const override {
        Citizen::Walk(destination);
        this->SingSong();
    }
private:
    const string FavouriteSong_;
};


class Teacher : public Citizen {
public:

    Teacher(const string& name, const string& subject) : Citizen(name, "Teacher"),
                                                         Subject_(subject) {}

    void Teach() const {
        cout << Type << ": " << Name << " teaches: " << Subject_ << endl;
    }

private:
    const string Subject_;
};


class Policeman : public Citizen {
public:
    explicit Policeman(const string& name) : Citizen(name, "Policeman") {}

    void Check(const Citizen& c) const {
        cout << Type << ": " << Name << " checks " << c.Type << ". " << c.Type << "'s name is: " << c.Name << endl;
    }
};


void VisitPlaces(const Citizen& c, const vector<string>& places) {
    for (const auto& p : places) {
        c.Walk(p);
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
