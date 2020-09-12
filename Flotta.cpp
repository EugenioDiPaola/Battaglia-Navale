#include"Nave.h"
#include"Flotta.h"

class Giocatore;

Flotta::Flotta()
{
	ptr_to_Giocatore = 0;
};

Flotta::Flotta(Giocatore * const PTR_TO_GIOCATORE)
	:ptr_to_Giocatore(PTR_TO_GIOCATORE)
{
	lista_punti_Nave_colpiti.resize(10, Punto(-1, -1, false));
};


flottaVectorDerived & Flotta::flottaOfFlottaGet()
{
	return flottaOfFlotta;
};
Giocatore * Flotta::ptr_to_GiocatoreGet()const
{
	return ptr_to_Giocatore;
};
std::vector<Punto> & Flotta::lista_punti_mare_colpitiGet()
{
	return lista_punti_mare_colpiti;
};
std::vector<Punto> & Flotta::lista_punti_Nave_colpitiGet()
{
	return lista_punti_Nave_colpiti;
};

void Flotta::ptr_to_GiocatoreSet(Giocatore & GIOCATORE)
{
	ptr_to_Giocatore = &GIOCATORE;
};
