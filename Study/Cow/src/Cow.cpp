
#include <iostream>
#include <cstring>
#include "Cow.h"


int main() {

Cow aaa("dima", "milk", 12);    //������ ������ aaa dima

aaa.ShowCow();
Cow bbb;                        // ������ ������ bbb �� ���������

bbb.ShowCow();
bbb = aaa;						// ����������� ������������ �� ���� �� �������� ������ ������� �����
								// ������ ����������� ����������� ���������� ������ aaa � bbb � aaa ������

bbb.ShowCow();
Cow ddd("sasha", "board", 33);
ddd.ShowCow();			// ������� ������ ddd �� ���������

aaa = ddd;						// ������ ddd ��������� aaa ����������� ������������ ������ ������ aaa � ������� ddd
aaa.ShowCow();
// ������� aaa
Cow ccc(aaa);
ccc.ShowCow();

	return 0;
}
