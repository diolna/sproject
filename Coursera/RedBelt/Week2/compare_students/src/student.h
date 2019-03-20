#pragma once

#include <map>
#include <string>
<<<<<<< HEAD
=======
#include "profile.h"
>>>>>>> d10ac15ab71b71aaceb2648d73d2cdffcd4a2fa1

using namespace std;

struct Student {
<<<<<<< HEAD
  string first_name;
  string last_name;
  map<string, double> marks;
  double rating;
=======

  string first_name=0;
  string last_name=0;
  map<string, double> marks;
  double rating=0;
>>>>>>> d10ac15ab71b71aaceb2648d73d2cdffcd4a2fa1

  bool operator < (const Student& other) const {
    return GetName() < other.GetName();
  }

  bool Less(const Student& other) const {
<<<<<<< HEAD
    return rating > other.rating;
  }

=======

    return rating > other.rating;
  }


>>>>>>> d10ac15ab71b71aaceb2648d73d2cdffcd4a2fa1
  string GetName() const {
    return first_name + " " + last_name;
  }
};
