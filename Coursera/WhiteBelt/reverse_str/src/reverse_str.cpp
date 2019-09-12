
#include <string>
#include <iostream>

using namespace std;


class ReversibleString {
public:

	ReversibleString() 	{}
	ReversibleString( const string & s){
		str = s;

	}
	void Reverse(){
		string temp;
		for (int i = str.size() - 1; i >= 0; --i) {
			temp.push_back(str[i]);
		}
		str = temp;

	}
	string ToString() const { return str; }

private:
	string str;


};


int main()
{

	ReversibleString s("live");
	s.Reverse();
	cout << s.ToString() << endl;

	s.Reverse();
	const ReversibleString& s_ref = s;
	string temp = s_ref.ToString();
	cout << temp << endl;

	ReversibleString empty;
	cout << '"' << empty.ToString() << '"' << endl;



	return 0;
}

