//������� #3        ���������� [][]             ���������� ������ ������ ��� ��������� ������       Visual Studio 2015
 #include <iostream>

using std::cout;
using std::cin;

class MyArr {
	unsigned m_row;			//���������� �����
	unsigned m_col;			//���������� �������
	int **arr;				//������������ ���������� � �������� �������
	MyArr() {}
public:
	MyArr(const unsigned, const unsigned);		//�������� ������������ � �����������, ��� ��������� �� ������
	~MyArr();		//�������� �����������

	unsigned row() const { return m_row; }		//������� ��� ������������ ����� �����
	unsigned col() const { return m_col; }		//������� ��� ������������ ����� �����

	int* operator[](const int i) {
		return arr[i];
	}

	const int* operator[](const int i) const {
		return arr[i];
	}
};

MyArr::MyArr(const unsigned row_, const unsigned col_):m_row(row_),m_col(col_) {
	arr = new int * [m_row];		//������ ��������� ������
	for (unsigned i = 0; i < m_row; i++) {
		arr[i] = new int[m_col];
	}
}


MyArr:: ~MyArr() {
	/*�������� ��������� ������*/
	for (unsigned i = 0; i < m_row; i++) {
		delete[]arr[i];
	}

	delete[]arr;
}




int main() {
	MyArr arr(10, 6);

	unsigned count = 0;	//��� ���������� �� �������

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
   //arr[0][0] = 100               // ��� ����������� ������� ������

	cin.get();
}




