//Листинг #3        Перегрузка [][]             Используем объект класса как двумерный массив       Visual Studio 2015
 #include <iostream>

using std::cout;
using std::cin;

class MyArr {
	unsigned m_row;			//количество строк
	unsigned m_col;			//количество колонок
	int **arr;				//указательная переменная в качестве массива
	MyArr() {}
public:
	MyArr(const unsigned, const unsigned);		//прототип конструктора с параметрами, для количеств на массив
	~MyArr();		//прототип деструктора

	unsigned row() const { return m_row; }		//функция для вытаскивания числа строк
	unsigned col() const { return m_col; }		//функция для вытаскивания числа строк

	int* operator[](const int i) {
		return arr[i];
	}

	const int* operator[](const int i) const {
		return arr[i];
	}
};

MyArr::MyArr(const unsigned row_, const unsigned col_):m_row(row_),m_col(col_) {
	arr = new int * [m_row];		//создаём двумерный массив
	for (unsigned i = 0; i < m_row; i++) {
		arr[i] = new int[m_col];
	}
}


MyArr:: ~MyArr() {
	/*зачищаем двумерный массив*/
	for (unsigned i = 0; i < m_row; i++) {
		delete[]arr[i];
	}

	delete[]arr;
}




int main() {
	MyArr arr(10, 6);

	unsigned count = 0;	//для заполнения по порядку

	for (unsigned i = 0; i < arr.row(); i++) {
		for (unsigned j = 0; j < arr.col(); j++) {
			arr[i][j] = count++;
		}
	}

	for (unsigned i = 0; i < arr.row(); i++) {
		for (unsigned j = 0; j < arr.col(); j++) {
			cout << arr[i][j] << '\t';
		}
		cout << "\n";
	}

	const MyArr arr2(10, 6);
   //arr[0][0] = 100               // для константого объекта нельзя

	cin.get();
}




