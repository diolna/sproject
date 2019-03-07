#include "test_runner.h"
#include <iostream>


using namespace std;



// Реализуйте здесь шаблонный класс Table
template <class T>
class Table{
	public:
	Table(size_t row_, size_t col_): m_row(row_), m_col(col_){
		arr = new T * [m_row];		//создаём двумерный массив
			for (unsigned i = 0; i < m_row; i++) {
				arr[i] = new T[m_col];
			}
	}

	T* operator[]( const size_t& index) {
	    return arr[index];
	  }

	  const T* operator[](size_t index) const {
	    return arr[index];
	  }
	  void Resize(const size_t& x=0, const size_t& y=0){
		  m_row =x;
		  m_col = y;
		  T** arr_temp;
		  arr_temp= new T*[m_row];
		  for(size_t i=0; i < m_row; i++){
			  arr_temp[i]= new T[m_col];
		  }
		  for(size_t x=0; x<m_row-1; x++){
			  for(size_t y=0; y<m_col-1; y++){
				  arr_temp[x][y]= arr[x][y];
			  }
		  }
		  cout << "test" << arr_temp[1][1]<< endl;
		  //copy(arr, arr+min(m_row, m_col),arr_temp);
		  delete[] arr;
		  arr=arr_temp;

	  }

	  pair<size_t, size_t> Size() const {
		       return {m_row, m_col};
	  }


private:
	size_t m_row, m_col;
	T** arr;
};


void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
 t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
//  t.Resize(3, 4);
// ASSERT_EQUAL(t.Size().first, 3u);
 // ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {

	Table<int> tt(2,2);
	tt[1][1] = 4;
	cout << tt[1][1];
	cout << endl;
	tt.Resize(5,6);
	cout << tt[1][1];


  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}
