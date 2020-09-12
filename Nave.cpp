#include<iostream>

#include"Nave.h"

Nave::Nave(int const LUNGHEZZA, int const INTEGRITA, std::string & NOME_NAVE)
	:lunghezza(LUNGHEZZA), integrita(INTEGRITA), nome_nave(NOME_NAVE)
{};

int Nave::lunghezzaGet() const
{ 
	return lunghezza;
};
int Nave::integritaGet() const
{
	return integrita;
};
std::string Nave::nome_naveGet() const
{
	return nome_nave;
};
std::vector<Punto> & Nave::lista_punti_occupatiGet()
{
	return lista_punti_occupati;
};

void Nave::lunghezzaSet(const int LUNGHEZZA)
{
	lunghezza = LUNGHEZZA;
};
void Nave::integritaSet(const int INTEGRITA)
{
	integrita = INTEGRITA;
};
void Nave::nome_naveSet(const std::string NOME_NAVE)
{
	nome_nave = NOME_NAVE;
};
void Nave::addPuntoAlista_punti_occupati(const Punto & PUNTO_DA_AGGIUNGERE)
{
	lista_punti_occupati.push_back(PUNTO_DA_AGGIUNGERE);
};

void Nave::lunghezzaPrint() const
{
	std::cout << lunghezza;
};
void Nave::integritaPrint() const
{
	std::cout << integrita;
};
void Nave::nome_navePrint() const
{
	std::cout << nome_nave;
};
void Nave::lista_punti_occupatiPrint() const
{
	for(std::vector<Punto>::const_iterator it = lista_punti_occupati.begin(); it < lista_punti_occupati.end(); ++it)
		(*it).PuntoPrint();
};

void Nave::NavePrintPerSe() const
{
	std::cout << "nome: " << nome_naveGet() << ", lunghezza: " << lunghezzaGet() << ", integrita': " << integritaGet() << ", lista dei punti occupati dalla nave: " << std::endl;
	lista_punti_occupatiPrint();
};

void Nave::NavePrintPerAvversario() const
{
	std::cout << nome_naveGet() << " (lunghezza: " << lunghezzaGet() << ")" << std::endl;
};
