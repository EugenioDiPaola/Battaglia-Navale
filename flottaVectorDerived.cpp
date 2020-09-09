#include<iostream>

#include"flottaVectorDerived.h"

flottaVectorDerived::flottaVectorDerived() : vector()
{};

std::vector<Nave *> & flottaVectorDerived::flottaGet()
{
	return flotta;
};

void flottaVectorDerived::flottaPrintPerSe()
{
	std::cout << "entrato dentro flottaPrintPerSe" << std::endl;
	std::vector<Nave *>::const_iterator it;
	for(it = (this->flottaGet()).begin(); it < (this->flottaGet()).end(); ++it)
	{
		(*it)->NavePrintPerSe();
	};
};

void flottaVectorDerived::flottaPrintPerAvversario()
{
	std::cout << "entrato dentro flottaPrintPerSe" << std::endl;
	std::vector<Nave *>::const_iterator it;
	for(it = (this->flotta).begin(); it < (this->flotta).end(); ++it)
	{
		(*it)->NavePrintPerAvversario();
	}
};

void flottaVectorDerived::NaveAdd(Nave & NAVE_DA_AGGIUNGERE)
{
	Nave * ptr_to_Nave_local = &NAVE_DA_AGGIUNGERE;
	flotta.push_back(ptr_to_Nave_local);
};
