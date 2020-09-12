#ifndef FLOTTA_H
#define FLOTTA_H

#include "flottaVectorDerived.h"

class Giocatore;

class Flotta{
	flottaVectorDerived flottaOfFlotta;
	Giocatore * ptr_to_Giocatore;
	std::vector<Punto>lista_punti_mare_colpiti;
	std::vector<Punto>lista_punti_Nave_colpiti;

public:
	Flotta();
	Flotta(Giocatore * const);

	Giocatore * ptr_to_GiocatoreGet() const;
	flottaVectorDerived & flottaOfFlottaGet();
	std::vector<Punto> & lista_punti_mare_colpitiGet();
	std::vector<Punto> & lista_punti_Nave_colpitiGet();

	void ptr_to_GiocatoreSet(Giocatore &);
};

#endif // FLOTTA_H
