#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

class Matrix {
public:
	Matrix(){num_row =0; num_cols =0;}
	Matrix(const int& n, const int& m){
		Reset(n,m);
	}
void Reset(const int& str, const int& cols){
	num_row = str;
	num_cols = cols;
	if( num_row<0 || num_cols<0){
		throw out_of_range("negative");
	}
	matrix.assign(num_row, vector<int>(num_cols));
	}
int	At(const int& n, const int& m) const {


		return matrix.at(n).at(m);
}

int& At(const int& colums, const int& string) {



	return matrix.at(colums).at(string);
}
int GetNumRows() const {

		return num_row;
}
int GetNumColumns() const {

		return num_cols;
}

private:
vector<vector<int>> matrix;
//vector<int> matrix_string;
int num_row;
int num_cols;

};


ostream& operator<<(ostream& stream, const Matrix& m){
			int num_string = m.GetNumRows();
			int num_col = m.GetNumColumns();
			stream << num_string << " " << num_col << endl;
			for(int x=0; x<num_string; ++x){
				if(x!=0) {stream << endl;}
				for(int y =0; y<num_col; ++y){
					stream << m.At(x,y) << " ";
				}
			}
			return stream;
}

istream& operator>>(istream& stream, Matrix& mat){
				int col, str;
				stream >> col >> str;
				mat.Reset(col, str);
				for(int x=0; x<col; ++x){
					for(int y =0; y<str; ++y){
						stream >>  mat.At(x,y);
					}
				}

	return stream;
}
Matrix operator+(const Matrix& lhs, const Matrix& rhs){
	if(lhs.GetNumRows()!=rhs.GetNumRows()|| lhs.GetNumColumns()!=rhs.GetNumColumns()){
		throw invalid_argument("invalid dimention");
	}
	int rows = lhs.GetNumRows();
	int col = lhs.GetNumColumns();

	Matrix res(rows, col);
	for(int x=0; x< rows; ++x){
		for(int y=0; y< col;++y){
			res.At(x, y) = lhs.At(x, y) + rhs.At(x, y);
		}
	}
	return res;
}
bool operator==(const Matrix& lhs, const Matrix& rhs){
	if(lhs.GetNumRows()!=rhs.GetNumRows()|| lhs.GetNumColumns()!=rhs.GetNumColumns()){
			return false;
	}
	int rows = lhs.GetNumRows();
	int col = lhs.GetNumColumns();
	for(int x=0; x< rows; ++x){
			for(int y=0; y< col;++y){
				if(lhs.At(x, y)!=rhs.At(x, y)){
					return false;
				}
			}
		}
	return true;
}

int main() {
try{
  Matrix one;
  Matrix two;

  cin >> one >> two;

  cout << one + two << endl;
}catch(out_of_range&){return 0;}
catch(invalid_argument&){return 0;}
  return 0;
}
