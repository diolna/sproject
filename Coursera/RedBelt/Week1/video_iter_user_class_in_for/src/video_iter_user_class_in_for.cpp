
#include <iostream>
#include <vector>
using namespace std;

template<class Iterator>					//шаблонный класс обьявляет два итератора
struct IteratorRange{
private:
	Iterator first, last;
	int a;
public:
	IteratorRange(Iterator f, Iterator l, int a_): first(f), last(l), a(a_){}

	Iterator begin() const {return first;}	// необходимо явно определить методы для begin и end
	Iterator end() const {return last;}
};

/*

template <class T>
IteratorRange<typename vector<T>::iterator> Head(    // инстанцирование создание конкретного типа
		vector<T>& v, size_t top){					// из шаблона класса
	return {
		v.begin(), next(v.begin(), min(top, v.size()))
	};
}

*/
//template <typename Iterator>
//IteratorRange<Iterator> MakeRange(Iterator begin, Iterator end){
//	return IteratorRange<Iterator>{begin, end};
//}

int main() {

	cout << "test1 " << endl;
	pair p(4,true);



	vector<int> v ={1,2,3,4,5};

	//auto second_half =MakeRange(v.begin()+v.size()/2, v.end());
	IteratorRange second_half2(v.begin()+v.size()/2, v.end()-1,3);

	for(auto& i: second_half2){
		cout << i << " ";
	}
	cout << endl;
/*
	for(auto& i: Head(v,3)){        // Вызов шаблонной функции для итерирования до 3 шага.
		++i;						// возвращает итератор на 3 элемент.
	}
	for (auto i: v){
		cout << i << " ";
	}
*/
	return 0;
}
