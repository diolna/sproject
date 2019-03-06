
#include <iostream>
#include <vector>
using namespace std;

template<class Iterator>					//��������� ����� ��������� ��� ���������
struct IteratorRange{
	Iterator first, last;

	Iterator begin() const {return first;}	// ���������� ���� ���������� ������ ��� begin � end
	Iterator end() const {return last;}
};



template <class T>
IteratorRange<class vector<T>::iterator> Head(    // ��������������� �������� ����������� ����
		vector<T>& v, size_t top){					// �� ������� ������
	return {
		v.begin(), next(v.begin(), min(top, v.size()))
	};
}



int main() {

	vector<int> v ={1,2,3,4,5};

	for(auto& i: Head(v,3)){        // ����� ��������� ������� ��� ������������ �� 3 ����.
		++i;						// ���������� �������� �� 3 �������.
	}
	for (auto i: v){
		cout << i << " ";
	}

	return 0;
}
