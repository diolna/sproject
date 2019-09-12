#include "iostream"
#include "utility"
#include  <vector>
#include <map>
//#include <string>
//#include <sstream>
//#include <algorithm>


using namespace std;


template <typename V> vector<V> operator*(const vector<V>& lhs, const vector<V>& rhs);
template <typename First, typename Second> pair<First, Second> operator*(const pair<First, Second>& lhs, const pair<First, Second>& rhs);
template <typename Key, typename Value> map<Key,Value> operator*(const map<Key,Value>& lhs, const map<Key,Value>& rhs);
//template <typename Collection> string Join(const Collection& c, char d);
template <typename T> T Sqr(T x);
//template <typename T> ostream& operator<<( ostream& stream, const vector<T> v);
//template <typename First, typename Second> ostream& operator<<(ostream& out,const pair<First, Second>& p);

template <typename V>
vector<V> operator*(const vector<V>& lhs, const vector<V>& rhs) {
	vector<V> res;
	int index = 0;
	for (V i : lhs) {
		res.push_back(i*rhs[index]);
		index++;
	}
	return res;
}

template <typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second>& lhs, const pair<First, Second>& rhs) {
	pair<First, Second> res;
	First f = lhs.first* rhs.first;
	Second s = lhs.second* rhs.second;


	return make_pair(f,s);
}


template <typename Key, typename Value>
map<Key,Value> operator*(const map<Key,Value>& lhs, const map<Key,Value>& rhs) {
				map<Key,Value> res;
					for (auto i : lhs) {
						res[i.first] = i.second* i.second;

					}

	return res;
}

/*

template <typename Collection>
string Join(const Collection& c, char d) {
	stringstream ss;
	bool first = true;
	for (auto& i : c) {
		if(!first) {
			ss << d;
		}
		first = false;
		ss << i;
	}
	return ss.str();
}
*/
template <typename T>

T Sqr(T x) {
	return x*x;
}



/*
template <typename T>
ostream& operator<<( ostream& stream, const vector<T> v) {


	return stream <<"["<< Join(v, ',')<< "]";
}
template <typename First, typename Second>
ostream& operator<<(ostream& out,const pair<First, Second>& p) {
	out << "(" <<p.first << ",";
	out << p.second << ")";

	return out;
}
template <typename Key, typename Value>
ostream& operator<<(ostream& stream, const map<Key, Value> v) {

	return stream <<"{"<< Join(v, ',')<< "}";
}
*/

int main()
{
	// Пример вызова функции
	vector<int> v = {1, 2, 3};
	cout << "vector:";
	for (int x : Sqr(v)) {
	  cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
	  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
}

