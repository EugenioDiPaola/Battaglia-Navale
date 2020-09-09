#include"FlottaStandard.h"

FlottaStandard::FlottaStandard() : Flotta()
{
	std::string s0 = "Mina Navale";
	std::string s1 = "Fregata";
	std::string s2 = "Incrociatore";
	std::string s3 = "Sottomarino";
	std::string s4 = "Portaerei";

	Nave * MINA1 = new Nave(1, 1, s0);
	Nave * MINA2 = new Nave(1, 1, s0);
	Nave * MINA3 = new Nave(1, 1, s0);
	Nave * FREGATA1 = new Nave(2, 2, s1);
	Nave * FREGATA2 = new Nave(2, 2, s1);
	Nave * INCROCIATORE1 = new Nave(3, 3, s2);
	Nave * INCROCIATORE2 = new Nave(3, 3, s2);
	Nave * SOTTOMARINO = new Nave(4, 4, s3);
	Nave * PORTAEREI = new Nave(5, 5, s4);

	this->flottaOfFlottaGet().push_back(MINA1);
	this->flottaOfFlottaGet().push_back(MINA2);
	this->flottaOfFlottaGet().push_back(MINA3);
	this->flottaOfFlottaGet().push_back(FREGATA1);
	this->flottaOfFlottaGet().push_back(FREGATA2);
	this->flottaOfFlottaGet().push_back(INCROCIATORE1);
	this->flottaOfFlottaGet().push_back(INCROCIATORE2);
	this->flottaOfFlottaGet().push_back(SOTTOMARINO);
	this->flottaOfFlottaGet().push_back(PORTAEREI);
};
