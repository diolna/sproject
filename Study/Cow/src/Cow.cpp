
#include <iostream>
#include <cstring>
#include "Cow.h"


int main() {

Cow aaa("dima", "milk", 12);    //создал обьект aaa dima

aaa.ShowCow();
Cow bbb;                        // создал обьект bbb по умолчанию

bbb.ShowCow();
bbb = aaa;						// конструктор присваивания ни чего не создавал просто присвои полля
								// следом конструктор копирования скопировал обьект aaa в bbb а aaa удалил

bbb.ShowCow();
Cow ddd("sasha", "board", 33);
ddd.ShowCow();			// создали обьект ddd по умоляанию

aaa = ddd;						// обьект ddd присвоили aaa конструктор копироватиня заново создал aaa и удаллил ddd
aaa.ShowCow();
// удалили aaa
Cow ccc(aaa);
ccc.ShowCow();

	return 0;
}
