
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


class SearchServer {
public:
  SearchServer() = default;
  explicit SearchServer(istream& document_input);
  // ����������� ��������� ����� ����� ���������� ���� ����������
  // ���� �������� ��� ���� ������ �������� ������ ������� �� ���� ����������� ����� ��� �������
  // ���� ��������� ����� ������� �� �������� ��������� ����

  void UpdateDocumentBase(istream& document_input);
  //�������� ������� ���� ���������� �� �����, ������� ���������� � ������ document_input.
  //��� ���� �������� �� ������ ������ ����� ������ ����� ����� ������������� (docid) 0,
  //�������� �� ������ ������ � ������������� 1 � �.�.
  //
  // ����� ��� �� ������ ��������� �������������� ���������� � ����������� ������ SearchServer.


  void AddQueriesStream(istream& query_input, ostream& search_results_output);
  //��������� ����� ��������� ������� ����� ��������� �������� � �������� ����� ��� ������
  //����������� ������
  //���� ������ ��� ���� ������ � ������ query_input ������ ��������� ������ ������� �� ����
  // ����������� ����� ��� ����������� ��������� ��� �� ��� � � ���������� ����� � ��������
  // ������� �� �������� ��������� ����

  //��������� - ����� �������� �� ���� �������� ����������� ����������.
  //� �������� ��������� �������� ������� ������������� �������� �������� ������

  //� �������� ������� ������������� �� ����� ������������ ��������� ����������
  //��������� ���� ���� ������� � ��������.

  //������  ������ "the best capital"
  //London is the capital of great britain � 2
  //(����� "the" ������ � �������� 1 ���, ����� "best" � �� ����, ����� "capital" � 1 ���)
  // moscow is the capital of the russian federation � 3
  //(����� "the" ������ � �������� 2 ����, ����� "best" � �� ����, ����� "capital" � 1 ���)
  //paris is the capital of france � 2
  //("the" � 1, "best" � 0, "capital" � 1)

  //� ����� ����������, ��� �������� "moscow is the capital of the russian federation"
  //����������� �������� ����������� ������� "the best capital".

  // �����
  //��� ������� ���������� ������� ����� AddQueriesStream ������ ������� � �����
  //search_results_output ���� ������ � �������

  // [����� �������]: {docid: <��������>, hitcount: <��������>}
  //{docid: <��������>, hitcount: <��������>} ...,
  //���:
  //docid � ������������� ���������
  //hitcount � �������� ������� ������������� ��� ������� ���������((�� ���� ���������
  //            ���������� ��������� ���� ���� ������� � ������ ��������).
  //���������::
  //��������� � ���������� ������ ���������, hitcount ������� ����� ����, �� �����.
  //��� �������� hitcount ����� ��������� ������ ����� �������, �� ���� ����� �there�
  //�� �������� ���������� ����� �the�
};


int main() {

	const string doc1 = "london is the capital of great britain";
	const string doc2 = "moscow is the capital of the russian federation";
	istringstream doc_input1(doc1 + '\n' + doc2);
	SearchServer srv(doc_input1);

	const string query = "the capital";
	istringstream query_input1(query);
	srv.AddQueriesStream(query_input1, cout);

	istringstream doc_input2(doc2 + '\n' + doc1);
	srv.UpdateDocumentBase(doc_input2);
	istringstream query_input2(query);
	srv.AddQueriesStream(query_input2, cout);
//  ��� ���� ������ ��������
//	the capital: {docid: 1, hitcount: 3} {docid: 0, hitcount: 2}
//	the capital: {docid: 0, hitcount: 3} {docid:

	return 0;
}
