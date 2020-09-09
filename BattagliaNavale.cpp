#include"Giocatore.h"
#include"FunzioniGenerali.h"
#include"FlottaStandard.h"

int main()
{
	string nomegiocatore1 = "GIOCATORE1";
	string nomegiocatore2 = "GIOCATORE2";

	Giocatore GIOCATORE1(nomegiocatore1);
	Giocatore GIOCATORE2(nomegiocatore2);

	FlottaStandard flottastandard1;
	FlottaStandard flottastandard2;

	int lato = 10;
	//int lato;
	//std::cout << "fornire il lato del campo su cui giocare"; 
	//std::cin >> lato;

	partita(GIOCATORE1, GIOCATORE2, flottastandard1, flottastandard2, lato);

	return 0;
};
