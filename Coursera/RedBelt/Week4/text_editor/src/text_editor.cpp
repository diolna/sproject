#include <string>
#include <list>
#include "test_runner.h"
using namespace std;

class Editor {
 public:
  // ���������� ����������� �� ��������� � ����������� ������
  Editor() : kursor(text.end()){

  }
  void Left(){

		  --kursor;

  }
  void Right(){

		  ++kursor;


  }
  void Insert(char token){
	  text.insert(kursor, token);


  }
  void Cut(size_t tokens = 1){
	  auto it = kursor;
	  buffer.clear();
	  for(; tokens > 0; --tokens){
		  	  buffer.push_back(*kursor);
		  	 if(kursor==text.end()){break;}
	  		 ++kursor;
	  	  }
	  	  if(kursor==text.end()){text.erase(it, text.end());}else{
	 	  text.erase(it, kursor);}


  }
  void Copy(size_t tokens = 1){

	  	  buffer.clear();
	  	  for(; tokens > 0; --tokens){
	  		  	  buffer.push_back(*kursor);

	  	  		 ++kursor;
	  	  	  }

  }
  void Paste(){
	  text.insert(kursor, buffer.begin(), buffer.end());

  }
  string GetText() const{
	  string s;
	  for(auto it = text.begin(); it!= text.end(); ++it){
		  s += *it;
	  }
	  return s;
  }
	  string GetBuffer() const{
	  	  string s;
	  	  for(auto it = buffer.begin(); it!= buffer.end(); ++it){
	  		  s += *it;
	  	  }
	  	  return s;

  }
 private:
  list<char> text;
  list<char>::iterator kursor;
  list<char> buffer;
};

void TypeText(Editor& editor, const string& text) {
  for(char c : text) {
    editor.Insert(c);
  }
}

void TestEditing() {
  {
    Editor editor;

    const size_t text_len = 12;
    const size_t first_part_len = 7;
    TypeText(editor, "hello, world");

    for(size_t i = 0; i < text_len; ++i) {
      editor.Left();
    }
    editor.Cut(first_part_len);

    for(size_t i = 0; i < text_len - first_part_len; ++i) {
      editor.Right();
    }
    TypeText(editor, ", ");

    editor.Paste();

    editor.Left();
    editor.Left();
    editor.Cut(3);

    ASSERT_EQUAL(editor.GetText(), "world, hello");
  }
  {
    Editor editor;

    TypeText(editor, "misprnit");
    editor.Left();
    editor.Left();
    editor.Left();
    editor.Cut(1);
    editor.Right();
    editor.Paste();

    ASSERT_EQUAL(editor.GetText(), "misprint");
  }
}

void TestReverse() {
  Editor editor;

  const string text = "esreveR";
  for(char c : text) {
    editor.Insert(c);
    editor.Left();
  }

  ASSERT_EQUAL(editor.GetText(), "Reverse");
}

void TestNoText() {
  Editor editor;
  ASSERT_EQUAL(editor.GetText(), "");

  editor.Left();
  editor.Left();
  editor.Right();
  editor.Right();
  editor.Copy(0);
  editor.Cut(0);
  editor.Paste();

  ASSERT_EQUAL(editor.GetText(), "");
}

void TestEmptyBuffer() {
  Editor editor;

  editor.Paste();
  TypeText(editor, "example");
  editor.Left();
  editor.Left();
  editor.Paste();
  editor.Right();
  editor.Paste();
  editor.Copy(0);
  editor.Paste();
  editor.Left();
  editor.Cut(0);
  editor.Paste();

  ASSERT_EQUAL(editor.GetText(), "example");
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestEditing);
  RUN_TEST(tr, TestReverse);
  RUN_TEST(tr, TestNoText);
  RUN_TEST(tr, TestEmptyBuffer);

//  Editor editor;
//   const string text = "hello, world";
//   for (char c : text) {
//     editor.Insert(c);
//   }
//   // ������� ��������� ���������: `hello, world|`
//   for (size_t i = 0; i < text.size(); ++i) {
//     editor.Left();
//   }
//   // ������� ��������� ���������: `|hello, world`
//   editor.Cut(7);
//   // ������� ��������� ���������: `|world`
//   // � ������ ������ ��������� ����� `hello, `
//   for (size_t i = 0; i < 5; ++i) {
//     editor.Right();
//   }
//   // ������� ��������� ���������: `world|`
//   editor.Insert(',');
//   editor.Insert(' ');
//   // ������� ��������� ���������: `world, |`
//   editor.Paste();
//   // ������� ��������� ���������: `world, hello, |`
//   editor.Left();
//   editor.Left();
//   //������� ��������� ���������: `world, hello|, `
//   editor.Cut(3); // ����� �������� 2 �������
//   // ������� ��������� ���������: `world, hello|`
//   cout << editor.GetText();

  return 0;
}
