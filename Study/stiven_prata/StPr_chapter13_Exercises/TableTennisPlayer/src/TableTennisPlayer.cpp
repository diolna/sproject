
#include <iostream>
#include "tabtenn0.h"

using namespace std;

int main() {

	TableTennisPlayer player1("Chuk", "Brizzard", true);
	TableTennisPlayer player2("Tara", "Boomdea", false);
	RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
	rplayer1.Name();
//	if(rplayer1.HasTable())
//			std::cout << ": has a table.\n";
//			else
//				std::cout << " hasn`t a table.\n";
//
//	player1.Name();
//	if(player1.HasTable())
//		std::cout << ": has a table.\n";
//		else
//			std::cout << " hasn`t a table.\n";
//	player2.Name();
//		if(player2.HasTable())
//			std::cout << ": has a table.\n";
//			else
//				std::cout << " hasn`t a table.\n";

		rplayer1.Name();
		std::cout << "; Rating; " << rplayer1.Rating() << endl;
		RatedPlayer rplayer2(1212, rplayer1);
		std:: cout << "Name: ";
		rplayer2.Name();
		std::cout << "; Rating: "  << rplayer2.Rating() << endl;



	return 0;
}
