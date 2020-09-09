#include<iostream>

#include"FunzioniGenerali.h" 

void flottaPrintGeneralePerSe(Giocatore & GIOCATORE)
{
	for(std::vector<Nave *>::const_iterator it = GIOCATORE.flottaOfGiocatoreGet().flottaOfFlottaGet().begin(); it < GIOCATORE.flottaOfGiocatoreGet().flottaOfFlottaGet().end(); ++it)
	{
		std::cout << " ";
		(**it).NavePrintPerSe();
	};
};

void flottaPrintGeneralePerAvversario(Giocatore & GIOCATORE)
{
	for(std::vector<Nave *>::const_iterator it = GIOCATORE.flottaOfGiocatoreGet().flottaOfFlottaGet().begin(); it < GIOCATORE.flottaOfGiocatoreGet().flottaOfFlottaGet().end(); ++it)
	{
		std::cout << " ";
		(**it).NavePrintPerAvversario();
	};
};

void printGrigliaPerSe(Giocatore & GIOCATORE, int LATO)
{
	for(int i = 1; i <= LATO; ++i)
	{
		for(int j = 1; j <= LATO; ++j)
		{
			{
				std::vector<Punto>::iterator it1;
				std::vector<Punto>::iterator it2;
				std::vector<Nave *>::iterator it3;
				std::vector<Punto>::iterator it4;

				for(it1 = GIOCATORE.flottaOfGiocatoreGet().lista_punti_mare_colpitiGet().begin(); it1 < GIOCATORE.flottaOfGiocatoreGet().lista_punti_mare_colpitiGet().end(); ++it1)
				{
					if((*it1).ascissaGet() == i && (*it1).ordinataGet() == j)
					{
						std::cout << "x ";
						goto exit1
							;
					}
				};

				for(it2 = GIOCATORE.flottaOfGiocatoreGet().lista_punti_Nave_colpitiGet().begin(); it2 < GIOCATORE.flottaOfGiocatoreGet().lista_punti_Nave_colpitiGet().end(); ++it2)
				{
					if((*it2).ascissaGet() == i && (*it2).ordinataGet() == j)
					{
						std::cout << "X ";
						goto exit1;
					};
				};

				for(it3 = GIOCATORE.flottaOfGiocatoreGet().flottaOfFlottaGet().begin(); it3 < GIOCATORE.flottaOfGiocatoreGet().flottaOfFlottaGet().end(); ++it3)
				{
					for(it4 = (*it3)->lista_punti_occupatiGet().begin(); it4 < (*it3)->lista_punti_occupatiGet().end(); ++it4)
					{
						if((*it4).ascissaGet() == i && (*it4).ordinataGet() == j && (*it4).e_stato_colpitoGet() == false)
						{
							std::cout << (*it3)->lunghezzaGet() << " ";
							goto exit1;
						};

						if((*it4).ascissaGet() == i && (*it4).ordinataGet() == j && (*it4).e_stato_colpitoGet() == true)
						{
							std::cout << "X ";
							goto exit1;
						};
					};
				};

				std::cout << ". ";

			exit1:
				{
				};
			};
		};
		std::cout << endl;
	};
};


void printGrigliaPerAvversario(Giocatore & GIOCATORE, int LATO)
{
	for(int i = 1; i <= LATO; ++i)
	{
		for(int j = 1; j <= LATO; ++j)
		{
			std::vector<Punto>::iterator it1;
			std::vector<Punto>::iterator it2;
			std::vector<Nave *>::iterator it3;
			std::vector<Punto>::iterator it4;

			for(it1 = GIOCATORE.flottaOfGiocatoreGet().lista_punti_mare_colpitiGet().begin(); it1 < GIOCATORE.flottaOfGiocatoreGet().lista_punti_mare_colpitiGet().end(); ++it1)
			{
				if((*it1).ascissaGet() == i && (*it1).ordinataGet() == j)
				{
					std::cout << "x ";
					goto exit1;
				};
			};

			for(it2 = GIOCATORE.flottaOfGiocatoreGet().lista_punti_Nave_colpitiGet().begin(); it2 < GIOCATORE.flottaOfGiocatoreGet().lista_punti_Nave_colpitiGet().end(); ++it2)
			{
				if((*it2).ascissaGet() == i && (*it2).ordinataGet() == j)
				{
					std::cout << "X ";
					goto exit1;
				};
			};

			for(it3 = GIOCATORE.flottaOfGiocatoreGet().flottaOfFlottaGet().begin(); it3 < GIOCATORE.flottaOfGiocatoreGet().flottaOfFlottaGet().end(); ++it3)
			{
				for(it4 = (*it3)->lista_punti_occupatiGet().begin(); it4 < (*it3)->lista_punti_occupatiGet().end(); ++it4)
				{
					if((*it4).ascissaGet() == i && (*it4).ordinataGet() == j && (*it4).e_stato_colpitoGet() == false)
					{
						std::cout << ". ";
						goto exit1;
					};
					if((*it4).ascissaGet() == i && (*it4).ordinataGet() == j && (*it4).e_stato_colpitoGet() == true)
					{
						std::cout << "X ";
						goto exit1;
					};
				};

			};
			std::cout << ". ";
		exit1:
			{
			};
		};
		std::cout << endl;
	};
};

void ColpisciPunto(int ASCISSA, int ORDINATA, Giocatore & GIOCATORE_DA_COLPIRE)
{
	Punto punto_da_aggiungere(ASCISSA, ORDINATA, true);
	{
		std::vector<Punto>::iterator it1;
		std::vector<Punto>::iterator it2;
		std::vector<Nave *>::iterator it3;
		std::vector<Punto>::iterator it4;

		for(it1 = GIOCATORE_DA_COLPIRE.flottaOfGiocatoreGet().lista_punti_mare_colpitiGet().begin(); it1 < GIOCATORE_DA_COLPIRE.flottaOfGiocatoreGet().lista_punti_mare_colpitiGet().end(); ++it1)
		{
			if((*it1).ascissaGet() == ASCISSA && (*it1).ordinataGet() == ORDINATA)
			{
				std::cout << "Questo punto di mare e' gia' stato colpito. " << endl << endl;
				goto exit;
			};
		};

		for(it2 = GIOCATORE_DA_COLPIRE.flottaOfGiocatoreGet().lista_punti_Nave_colpitiGet().begin(); it2 < GIOCATORE_DA_COLPIRE.flottaOfGiocatoreGet().lista_punti_Nave_colpitiGet().end(); ++it2)
		{
			if((*it2).ascissaGet() == ASCISSA && (*it2).ordinataGet() == ORDINATA)
			{
				std::cout << "Questo punto di una nave e' gia' stato colpito. " << endl << endl;
				goto exit;
			};
		};


		for(it3 = GIOCATORE_DA_COLPIRE.flottaOfGiocatoreGet().flottaOfFlottaGet().begin(); it3 < GIOCATORE_DA_COLPIRE.flottaOfGiocatoreGet().flottaOfFlottaGet().end(); ++it3)
		{
			for(it4 = (*it3)->lista_punti_occupatiGet().begin(); it4 < (*it3)->lista_punti_occupatiGet().end(); ++it4)
			{
				if((*it4).ascissaGet() == ASCISSA && (*it4).ordinataGet() == ORDINATA)
				{
					std::cout << "hai colpito una nave di " << GIOCATORE_DA_COLPIRE.nome_giocatoreGet() << "!" << endl << endl;

					int temporary_local = ((*it3)->integritaGet());
					(*it3)->integritaSet(--temporary_local);
					(*it4).e_stato_colpitoSet(true);
					GIOCATORE_DA_COLPIRE.flottaOfGiocatoreGet().lista_punti_Nave_colpitiGet().push_back(punto_da_aggiungere);

					if((*it3)->integritaGet() == 0)
					{
						std::cout << "hai affondato " << (*it3)->nome_naveGet() << " di " << GIOCATORE_DA_COLPIRE.nome_giocatoreGet() << "." << endl;
						(*it3)->~Nave();
						*it3 = NULL;
						it3 = (GIOCATORE_DA_COLPIRE.flottaOfGiocatoreGet().flottaOfFlottaGet().erase(it3));
					}
					goto exit;
				};
			};
		};

		std::cout << "non hai colpito alcuna nave di " << GIOCATORE_DA_COLPIRE.nome_giocatoreGet() << "!" << endl << endl;
		GIOCATORE_DA_COLPIRE.flottaOfGiocatoreGet().lista_punti_mare_colpitiGet().push_back(punto_da_aggiungere);
	}

exit:
	{
	};
};

void scegliEColpisciPunto(Giocatore & GIOCATORE_IN_DIFESA)
{
	int ascissa, ordinata;
	std::cout << "fornisci le coordinate del punto che vuoi colpire: " << endl;
	std::cin >> ascissa >> ordinata;
	std::cout << endl;
	ColpisciPunto(ascissa, ordinata, GIOCATORE_IN_DIFESA);
};

void turno(Giocatore & GIOCATORE_IN_ATTACCO, Giocatore & GIOCATORE_IN_DIFESA, int LATO)
{
	std::cout << "-----------------------------------inizio turno di " << GIOCATORE_IN_ATTACCO.nome_giocatoreGet() << "------------------------------------" << endl;
	std::cout << "Giocatore " << GIOCATORE_IN_ATTACCO.nome_giocatoreGet() << ", e' il tuo turno di attaccare, questo e' cio' che vedi del tuo avversario: " << endl;

	printGrigliaPerAvversario(GIOCATORE_IN_DIFESA, LATO);

	std::cout << "Giocatore " << GIOCATORE_IN_ATTACCO.nome_giocatoreGet() << ", le navi non ancora affondate del tuo avversario sono: " << endl << endl;

	flottaPrintGeneralePerAvversario(GIOCATORE_IN_DIFESA);
	std::cout << endl;
	scegliEColpisciPunto(GIOCATORE_IN_DIFESA);

	flottaPrintGeneralePerAvversario(GIOCATORE_IN_DIFESA);

	printGrigliaPerSe(GIOCATORE_IN_DIFESA, LATO);
	std::cout << "-----------------------------------fine turno di " << GIOCATORE_IN_ATTACCO.nome_giocatoreGet() << "------------------------------------" << endl;
	std::cout << endl;
};

bool viEUnVincitoreTra(Giocatore & GIOCATORE1, Giocatore & GIOCATORE2)
{
	if(GIOCATORE1.flottaOfGiocatoreGet().flottaOfFlottaGet().empty() && !GIOCATORE2.flottaOfGiocatoreGet().flottaOfFlottaGet().empty()) return true;
	if(!GIOCATORE1.flottaOfGiocatoreGet().flottaOfFlottaGet().empty() && GIOCATORE2.flottaOfGiocatoreGet().flottaOfFlottaGet().empty()) return true;
	if(!GIOCATORE1.flottaOfGiocatoreGet().flottaOfFlottaGet().empty() && !GIOCATORE2.flottaOfGiocatoreGet().flottaOfFlottaGet().empty()) return false;
};

void battaglia(Giocatore & GIOCATORE1, Giocatore & GIOCATORE2, int LATO)
{
	int i = 2;
	while(viEUnVincitoreTra(GIOCATORE1, GIOCATORE2) == false)
	{
		if(i % 2 == 0) turno(GIOCATORE1, GIOCATORE2, LATO);
		if(i % 2 == 1) turno(GIOCATORE2, GIOCATORE1, LATO);
		++i;
	}
};

void posizionamentoGiocatore(Giocatore & GIOCATORE, int LATO)
{
	std::cout << "Giocatore " << GIOCATORE.nome_giocatoreGet() << ", ora puoi posizionare le tue navi." << endl;

	std::vector<Nave *>::iterator it;
	for(it = GIOCATORE.flottaOfGiocatoreGet().flottaOfFlottaGet().begin(); it < GIOCATORE.flottaOfGiocatoreGet().flottaOfFlottaGet().end(); ++it)
	{
		std::cout << "Giocatore " << GIOCATORE.nome_giocatoreGet() << ", questo e' cio' che tu vedi del tuo campo: " << endl;

		printGrigliaPerSe(GIOCATORE, LATO);

		std::cout << "Giocatore " << GIOCATORE.nome_giocatoreGet() << ", stai per posizionare " << (*it)->nome_naveGet() << " (lunghezza: " << (*it)->lunghezzaGet() << ")" << endl;
		std::cout << "Giocatore " << GIOCATORE.nome_giocatoreGet() << ", fornisci ascissa, ordinata e direzione in cui posizionare (0 per orizzonatale, 1 per verticale):" << endl;

		int ascissa, ordinata;
		bool direzione;
		std::cin >> ascissa >> ordinata >> direzione;
		std::cout << endl;

		if(direzione == 0) for(int i = 0; i < (*it)->lunghezzaGet(); i++)
		{
			Punto puntolocal(ascissa, ordinata + i, false);
			(*it)->lista_punti_occupatiGet().push_back(puntolocal);
		};

		if(direzione == 1) for(int i = 0; i < (*it)->lunghezzaGet(); i++)
		{
			Punto puntolocal(ascissa + i, ordinata, false);
			(*it)->lista_punti_occupatiGet().push_back(puntolocal);
		};
	};
	std::cout << "Giocatore " << GIOCATORE.nome_giocatoreGet() << ", questo e' il tuo campo a fine posizionamento: " << endl;

	printGrigliaPerSe(GIOCATORE, LATO);
};

void dichiarazioneVincitore(Giocatore & GIOCATORE1, Giocatore & GIOCATORE2)
{
	std::cout << "il vincitore di questa partita e' il giocatore ";
	if(GIOCATORE1.flottaOfGiocatoreGet().flottaOfFlottaGet().empty() && !GIOCATORE2.flottaOfGiocatoreGet().flottaOfFlottaGet().empty())
	{
		std::cout << GIOCATORE2.nome_giocatoreGet() << endl;
		int punteggiolocal = GIOCATORE2.punteggioGet();
		GIOCATORE2.punteggioSet(punteggiolocal++);

	};

	if(!GIOCATORE1.flottaOfGiocatoreGet().flottaOfFlottaGet().empty() && GIOCATORE2.flottaOfGiocatoreGet().flottaOfFlottaGet().empty())
	{
		std::cout << GIOCATORE1.nome_giocatoreGet() << endl;
		int punteggiolocal = GIOCATORE2.punteggioGet();
		GIOCATORE1.punteggioSet(punteggiolocal++);
	};

	if(GIOCATORE1.flottaOfGiocatoreGet().flottaOfFlottaGet().empty() && GIOCATORE2.flottaOfGiocatoreGet().flottaOfFlottaGet().empty()) std::cout << "la partita è finita in parità" << endl;
};

void partita(Giocatore & GIOCATORE1, Giocatore & GIOCATORE2, Flotta & FLOTTA_PER_GIOCATORE2, Flotta & FLOTTA_PER_GIOCATORE1, int LATO = 10)
{

	GIOCATORE1.flottaOfGiocatoreGet() = FLOTTA_PER_GIOCATORE1;
	GIOCATORE2.flottaOfGiocatoreGet() = FLOTTA_PER_GIOCATORE2;

	std::cout << endl << "---------------POSIZIONAMENTO GIOCATORE1:-------------" << endl;
	posizionamentoGiocatore(GIOCATORE1, LATO);

	std::cout << endl << "---------------POSIZIONAMENTO GIOCATORE2:-------------" << endl;
	posizionamentoGiocatore(GIOCATORE2, LATO);

	std::cout << endl << "---------------COMINCIA LA BATTAGLIA!-----------------" << endl;
	battaglia(GIOCATORE1, GIOCATORE2, LATO);

	dichiarazioneVincitore(GIOCATORE1, GIOCATORE2);
};

