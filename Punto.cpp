#include<iostream>

#include "Punto.h"

Punto::Punto(int const & ASCISSA, int const & ORDINATA, bool const & COLPITO)
	:ascissa(ASCISSA), ordinata(ORDINATA), e_stato_colpito(COLPITO)
{};

int Punto::ascissaGet() const
{
	return ascissa;
};
int Punto::ordinataGet() const
{
	return ordinata;
};
bool Punto::e_stato_colpitoGet() const
{
	return e_stato_colpito;
};

void Punto::ascissaSet(const int ASCISSA)
{
	ascissa = ASCISSA;
};
void Punto::ordinataSet(const int ORDINATA)
{
	ordinata = ORDINATA;
};
void Punto::e_stato_colpitoSet(const bool E_STATO_COLPITO)
{
	e_stato_colpito = E_STATO_COLPITO;
};

void Punto::ascissaPrint() const
{
	std::cout << ascissa;
};
void Punto::ordinataPrint() const
{
	std::cout << ordinata;
};
void Punto::e_stato_colpitoPrint() const
{
	std::cout << e_stato_colpito;
};
void Punto::PuntoPrint() const
{
	std::cout << "(" << ascissa << "," << ordinata << ")" << " e' stato colpito? " << e_stato_colpito << std::endl;
};
