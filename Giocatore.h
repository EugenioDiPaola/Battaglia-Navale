#ifndef GIOCATORE_H
#define GIOCATORE_H

#include<string>

#include"Flotta.h"

class Giocatore{
	std::string nome_giocatore;
	Flotta flottaOfGiocatore;
	int punteggio;

public:
	Giocatore();
	Giocatore(const std::string &);
	Giocatore(const std::string &, const Flotta &, const int &);
	~Giocatore();

	std::string nome_giocatoreGet();
	Flotta & flottaOfGiocatoreGet();
	int punteggioGet();

	void nome_giocatoreSet(const std::string & STRING); 
	void punteggioSet(int PUNTEGGIO);

	void nome_giocatorePrint();
	void punteggioPrint();
};

#endif // GIOCATORE_H
