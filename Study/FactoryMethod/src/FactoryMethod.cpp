#include <iostream>
#include <string>
#include "Pizza.h"
#include "NYTypePizzaStore.h"
#include "ChikagoTypePizzaStore.h"
using namespace std;

using namespace std;

int main()
{
	PizzaStore *NYStore = new NYTypePizzaStore; // должен знать фабрику. В єтой строчке магазни пицці в ньюйорку


	Pizza* aaa = NYStore->OrderPizza("vegi"); // Должен знать тип пицці Опять таки єта информация в фабрике.

	//	Но создание обьекта конкретной пиццы скрыто Создание пицці может біть очень сложнім. Фабрика знает какие типі может
	//созданвать В фабрику добавляем новій тип при помощи if  иди switch

	aaa->Prepare();
	cout << aaa->GetName();
	cout << endl;
	cout << "2 metod " << endl;

	PizzaStore *ChikagoStore = new ChikagoTypePizzaStore;
	Pizza* chikago = ChikagoStore->OrderPizza("cheese");
	chikago ->Prepare();
	cout << chikago->GetName();



	return 0;
}

