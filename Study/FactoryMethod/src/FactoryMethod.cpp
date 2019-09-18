#include <iostream>
#include <string>
#include "Pizza.h"
#include "NYTypePizzaStore.h"
#include "ChikagoTypePizzaStore.h"
using namespace std;

using namespace std;

int main()
{
	PizzaStore *NYStore = new NYTypePizzaStore; // ������ ����� �������. � ���� ������� ������� ����� � ��������


	Pizza* aaa = NYStore->OrderPizza("vegi"); // ������ ����� ��� ����� ����� ���� ��� ���������� � �������.

	//	�� �������� ������� ���������� ����� ������ �������� ����� ����� ��� ����� ������. ������� ����� ����� ��� �����
	//���������� � ������� ��������� ���� ��� ��� ������ if  ��� switch

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

