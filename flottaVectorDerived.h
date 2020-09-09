#ifndef FLOTTAVECTORDERIVED_H
#define FLOTTAVECTORDERIVED_H

#include<vector>
#include"Nave.h"

class Nave;

class flottaVectorDerived : public std::vector<Nave *>{
	std::vector<Nave *> flotta;

public:

	flottaVectorDerived();

	std::vector<Nave *> & flottaGet();

	void flottaPrintPerSe();
	void flottaPrintPerAvversario();
	void NaveAdd(Nave &);
};

#endif // FLOTTAVECTORDERIVED_H
    