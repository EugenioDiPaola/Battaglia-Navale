#include<iostream>

#include"Giocatore.h"
#include"FunzioniGenerali.h"
#include"FlottaStandard.h"

int main()
{
	std::string nomegiocatore1 = "GIOCATORE1";
	std::string nomegiocatore2 = "GIOCATORE2";

	Giocatore GIOCATORE1(nomegiocatore1);
	Giocatore GIOCATORE2(nomegiocatore2);

	FlottaStandard flottastandard1;
	FlottaStandard flottastandard2;

	int lato = 0;

	std::cout << "Giocatori! Fornite il lato del campo su cui giocare:" << "\n";
	std::cin >> lato;

	partita(GIOCATORE1, GIOCATORE2, flottastandard1, flottastandard2, lato);

	return 0;
};
