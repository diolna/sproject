#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <math.h>
#include <iomanip>

using namespace std;


class Figure {
public:
virtual string Name() =0;
virtual double Perimeter() =0;
virtual double Area() =0;

};

class Triangle: public Figure {
public:
	Triangle(double& aa, double& bb, double& cc){a_=aa; b_=bb; c_=cc;}

	string Name() override {

		return "TRIANGLE";

	}
	double Perimeter() override {
		return   a_+b_+c_;


	}
	double Area() override {
		double p = (a_+b_+c_)/2;
		return (sqrt(p*(p-a_)*(p-b_)*(p-c_)));

			}

private:
	double a_, b_, c_;
};



class Rect: public Figure {
public:
	Rect(double& w, double& h){width= w; height = h; }
	string Name() override {
	return "RECT";

}
	double Perimeter() override {
	return  2*width+ 2*height;


}
	double Area() override {
	return width*height;


}
private:
	double width, height;

};

class Circle : public Figure {
public:
	Circle( const double& r): radius(r){}
	string Name() override {
		return "CIRCLE";

	}
	double Perimeter() override {
		return 2*3.14*radius;


	}
	double Area() override {
		return 3.14*radius*radius;


	}

private:
	 const double radius;

};

shared_ptr<Figure> CreateFigure( istringstream& is){
		string figure;
		is>> figure;
		if(figure == "RECT"){
			double width, height;
			is>> width >>height;


			return make_shared<Rect>(width, height );
		}else if(figure == "TRIANGLE"){
			double a,b,c;
			is>>a>>b>>c;
			return make_shared<Triangle>(a,b,c);
		}else if (figure == "CIRCLE"){
			double radius;
			is>> radius;
			return make_shared<Circle>(radius);
		}

}

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      figures.push_back(CreateFigure(is));

    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
