
#include <iostream>
#include <vector>
using namespace std;

template<class Iterator>					//шаблонный класс обьявляет два итератора
struct IteratorRange{
	Iterator first, last;

	Iterator begin() const {return first;}	// необходимо явно определить методы для begin и end
	Iterator end() const {return last;}
};



template <class T>
IteratorRange<class vector<T>::iterator> Head(    // инстанцирование создание конкретного типа
		vector<T>& v, size_t top){					// из шаблона класса
	return {
		v.begin(), next(v.begin(), min(top, v.size()))
	};
}



int main() {

	vector<int> v ={1,2,3,4,5};

	for(auto& i: Head(v,3)){        // Вызов шаблонной функции для итерирования до 3 шага.
		++i;						// возвращает итератор на 3 элемент.
	}
	for (auto i: v){
		cout << i << " ";
	}

	return 0;
}
