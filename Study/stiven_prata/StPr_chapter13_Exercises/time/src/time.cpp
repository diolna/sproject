
#include <iostream>
#include <string>
#include "time.h"



int main() {


	char x[20] = {"wwwwwww"};
	char* n = x;

	n = "aaaaaa";
	std::cout << n << std::endl;
	std::cout << n << std::endl;
	std::cout << "x[2] = " <<  x << std::endl;


	A1 aaa;
	B1 bbb;
	A1* p = & bbb;





  aaa.Show();
  bbb.Show();
  p->Show();


	return 0;



}



