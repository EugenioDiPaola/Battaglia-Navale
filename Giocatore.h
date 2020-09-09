#ifndef GIOCATORE_H
#define GIOCATORE_H

#include"Flotta.h"

class Giocatore{
	string nome_giocatore;
	Flotta flottaOfGiocatore;
	int punteggio;

public:
	Giocatore();
	Giocatore(const string &);
	Giocatore(const string &, const Flotta &, const int &);
	~Giocatore();

	string nome_giocatoreGet();
	Flotta & flottaOfGiocatoreGet();
	int punteggioGet();

	void nome_giocatoreSet(const string & STRING); 
	void punteggioSet(int PUNTEGGIO);

	void nome_giocatorePrint();
	void punteggioPrint();
};

#endif // GIOCATORE_H
