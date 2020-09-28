#include <iostream>
#include <vector>
#include <string>
using namespace std;

//struct box
//	{
//		char marker[40];
//		float height;
//		float width;
//		float length;
//		float volume;
//	};

//double Garman(double x, double y);

//int* Enter(int * );
//void Display(const int*, const double);
//double Res(const int*);
//void EnterVector(vector<int>&);
//void DisplayVector(vector<int>&, double);
//double  ResVector(vector<int>&);
//
//void StructFunc(const box);
//void StructFunc1(box *);

//const int SLEN =30;
//
//struct student {
//	char fullname[SLEN];
//	char hobby[SLEN];
//	int opplevel;
//};
//
//int getinfo(student pa[], int n);
//void display(student st);
//void display2(const student * ps);
//void display3(const student [], int);

double calculate(double, double, double (*func)(double, double));
double add(double , double);
double minus1(double, double);


int main() {

//	// number 1
//	double x,y;
//
//	cout << "Enter x, y" << endl;
//	cin >> x >> y;
//
//	while(x !=0 && y != 0){
//
//
//		cout << "Garman x= " << x << " y= " << y << " "
//				<< Garman(x,y)<< endl;
//		cout << "Enter x, y" << endl;
//				cin >> x >> y;
//	}
//
//
//    cout << "The end";
//
//    // number 1_1
//
//    do{
//    	cout << "Enter x1, y1 " << endl;
//    	cin >> x >> y;
//    	Garman(x, y);
//    	if(x != 0 && y != 0) cout << Garman(x,y);
//     }while(x != 0 && y != 0);
//    cout << "The end 1";
//
//
//
//	return 0;
//	// number 2
//	int chet[10] = {0,0,0,0,0,0,0,0,0,0};
//	int* chet_point = &chet[0];
//	chet_point = Enter(&chet[0]);
//	Display(chet_point, Res(chet_point));
//
////	return 0;
//	//number 2_2
//	vector<int> v;
//	EnterVector(v);
//	DisplayVector(v, ResVector(v));

	// number 3

//    box b=
//    {
//
//   "dfdfd",
//   30,
//     20,
//    45,
//    400
//    };
//    StructFunc(b);
//    StructFunc1(&b);
//    cout << b.volume << endl;

	// number 8


//	int aa;
//	char cc[3];
//	cout << "Enter number ";
//	cin >> aa;
//	cin.get();
//	cout << endl << "Enter string ";
//	cin.getline(cc, 4);
//
//	cout << endl << aa << " " << cc << endl;;
//
//	cout << "Enter class size: ";
//	int class_size;
//	cin >> class_size;
//	while(cin.get() != '\n')
//		continue;
//	student * ptr_stu = new student[class_size];
//	int entered = getinfo(ptr_stu, class_size);
//	for(int i=0; i < entered; i++){
//		display(ptr_stu[i]);
//		display2(&ptr_stu[i]);
//	}
//	display3(ptr_stu, entered);
//	delete [] ptr_stu;
//	cout << "Done\n";

	// number 9
	cout << calculate(2.5, 10.4, add);
	cout << calculate(2.5, 10.4, minus1);

	return 0;
};

double calculate(double x, double y, double(*f)(double a, double b)){
	return (*f)(x, y);
}
double add(double x, double y){
	return x + y;
}

double minus1(double x, double y){
	return x - y;
}

//int getinfo(student pa[], int n)
//{
//	for(int i=0; i < n; i++){
//
//		cout << "Enter fullname " << i + 1 << " student ";
//
//		cin.getline(pa[i].fullname, SLEN);
//
//		if(pa[i].fullname[0] == '\0') {
//			cout << endl;
//			return (i + 1);
//		}
//
//
//
//		cout << endl;
//		cout << "Enter hobbe " << i + 1 << " student ";
//		cin.getline(pa[i].hobby, SLEN);
//		cout << endl;
//		cout << "Enter level oop " << i + 1 << " student ";
//		cin >> pa[i].opplevel;
//		cin.get();
//		cout << endl;
//
//	}
//	return n;
//}
//void display(student st){
//	cout << st.fullname << " " << st.hobby << " " << st.opplevel << endl;
//}
//void display2(const student *ps){
//	cout << ps->fullname << " " << ps->hobby << " " << ps->opplevel << endl;
//}
//
//void display3( const student pa[], int n){
//	for(int i=0; i < n; i++){
//		cout << pa[i].fullname << " " << pa[i].hobby << " " << pa[i].opplevel << endl;
//	}
//}


//double Garman(double x, double y){
//	return 2*x*y/(x + y);
//}
//
//int* Enter(int * temp){
//	int i = 0;
//
//	int value;
//	while(cin >> value){
//		if(i == 9){
//			temp[i] = value;
//			cout << "i = " << i << " temp[i] = " << temp[i] << endl;
//
//			break;
//		}
//		temp[i] = value;
//		cout << "i = " << i << " temp[i] = " << temp[i];
//		i++;
//
//
//	}
//	return &temp[0];
//}
//
//double Res(const int* m){
//	double res = 0;
//	for(int i =0; i <= 9; i++){
//		res = res + m[i];
//	}
//	return res/10;
//}
//
//void Display(const int* m, const double v){
//	for(int i = 0; i <= 9; i++){
//		cout << m[i] << " ";
//	}
//	cout << v << endl;
//}
//void EnterVector(vector<int>& v){
//	int value;
//	int i = 0;
//	while(cin >> value){
//
//		v.push_back(value);
//		i++;
//		if(i == 10) break;
//	}
//}
//
//void DisplayVector(vector<int> &v, double valve){
//	for(const int i : v){
//		cout << i << " ";
//	}
//	cout << valve;
//}
//
//double  ResVector(vector<int>& v){
//	double value = 0;
//	for(const int i : v){
//			value = value + i;
//		}
//	return value/10;
//}
//void StructFunc(const box b){
//		cout << b.marker << endl;
//		cout << b.height << endl;
//		cout << b.width << endl;
//		cout << b.length << endl;
//}
//
//void StructFunc1(box *b){
//	b->volume = b->height* b->length * b->width;
//}
