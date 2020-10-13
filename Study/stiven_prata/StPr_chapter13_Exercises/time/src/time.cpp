
#include <iostream>
#include <string>
#include "time.h"



int main() {


	A1 aaa;
	B1 bbb;
	A1* p = & bbb;



  aaa.Show();
  bbb.Show("dima");
  p->Show();


	return 0;



}



