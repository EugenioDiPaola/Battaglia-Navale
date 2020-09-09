#ifndef NAVE_H
#define NAVE_H

#include<vector>
#include<string>
#include"Punto.h"

class Nave{
	int lunghezza, integrita;
	std::string nome_nave;
	std::vector<Punto> lista_punti_occupati;
	 
public:

	Nave(int const, int const, std::string &);

	int lunghezzaGet() const;
	int integritaGet() const;
	std::string nome_naveGet() const;
	std::vector<Punto> & lista_punti_occupatiGet();

	void lunghezzaSet(const int LUNGHEZZA);
	void integritaSet(const int INTEGRITA);
	void nome_naveSet(const std::string NOME_NAVE);
	void addPuntoAlista_punti_occupati(const Punto & PUNTO_DA_AGGIUNGERE);

	void lunghezzaPrint() const;
	void integritaPrint() const;
	void nome_navePrint() const;
	void lista_punti_occupatiPrint() const;
	void NavePrintPerSe() const;
	void NavePrintPerAvversario() const;
};

#endif // NAVE_H
