#include<iostream>

#include"Giocatore.h"

Giocatore::Giocatore()
{
	nome_giocatore = "Giocatore ";
	punteggio = 0;
};

Giocatore::Giocatore(const string & NOME_GIOCATORE)
	:nome_giocatore(NOME_GIOCATORE), flottaOfGiocatore(this)
{
	punteggio = 0;
};

Giocatore::Giocatore(const string & NOME_GIOCATORE, const Flotta & FLOTTAOFGIOCATORE, const int & PUNTEGGIO)
	:nome_giocatore(NOME_GIOCATORE), flottaOfGiocatore(FLOTTAOFGIOCATORE), punteggio(PUNTEGGIO)
{}

Giocatore::~Giocatore()
{
	std::cout << this->nome_giocatore << " e' stato eliminato" << endl;
};


Flotta & Giocatore::flottaOfGiocatoreGet()
{
	return flottaOfGiocatore;
};
int Giocatore::punteggioGet()
{
	return punteggio;
};
string Giocatore::nome_giocatoreGet()
{
	return nome_giocatore;
};

void Giocatore::nome_giocatoreSet(const string & STRING)
{
	nome_giocatore = STRING;
}
void Giocatore::punteggioSet(int PUNTEGGIO)
{
	punteggio = PUNTEGGIO;
}

void Giocatore::nome_giocatorePrint()
{
	std::cout << nome_giocatore;
};
void Giocatore::punteggioPrint()
{
	std::cout << punteggio;
};
