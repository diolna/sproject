#include "test_runner.h"
#include <iostream>


using namespace std;




// Реализуйте здесь шаблонный класс Table
template <class T>
class Table{
	public:
	Table(size_t row_, size_t col_): m_row(row_), m_col(col_){
		Resize(row_, col_);
	}


	  vector<T>& operator [] (size_t row) {


	        return matrix[row];

	    }



	  const vector<T>& operator [] (size_t row) const {


	  	        return matrix[row];

	  	    }



	  void Resize(const size_t& row, const size_t& col){
		 matrix.resize(row);
		 for(auto& i: matrix){
			 i.resize(col);
		 }

	 }



	  pair<size_t, size_t> Size() const {
		       return {matrix.size(), (matrix.empty() ? 0 : matrix[0].size())};
	  }


private:
	size_t m_row, m_col;
	vector<vector<T>> matrix;
};


void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
/*
	Table<int> tt(3,5);
	tt[2][3] = 4;
	cout << "tt[1][0] =" << tt[1][0];
	cout << endl;
	for(int i=0; i<3; ++i){
			for(int y=0; y<5; ++y){
				cout<< "tt[" << i << "][" << y << "]= " << tt[i][y] << endl;
		}
	}

	tt.Resize(0,0);
	cout <<"resize 00"<< endl;
	for(int i=0; i<8; ++i){
			for(int y=0; y<4; ++y){
				cout<< "tt[" << i << "][" << y << "]= " << tt[i][y] << endl;
		}
	}
			tt.Resize(8,9);
				cout <<"resize 8 9"<< endl;
				for(int i=0; i<8; ++i){
						for(int y=0; y<9; ++y){
							cout<< "tt[" << i << "][" << y << "]= " << tt[i][y] << endl;
					}
	}

*/
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}
