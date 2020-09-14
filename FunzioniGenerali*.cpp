#include<iostream>
#include<map>
#include<algorithm>

#include"FunzioniGenerali.h" 



const std::vector<char> alfabeto_minuscolo = {'a','b','c','d','e','f','g','h','i','l','m','n','o','p','q','r','s','t','u','v','z'};

const std::vector<char> alfabeto_maiuscolo = {'A','B','C','D','E','F','G','H','I','L','M','N','O','P','Q','R','S','T','U','V','Z'};

const std::vector<char> alfabeto_maiuscolo_e_minuscolo = {'a','b','c','d','e','f','g','h','i','l','m','n','o','p','q','r','s','t','u','v','z','A','B','C','D','E','F','G','H','I','L','M','N','O','P','Q','R','S','T','U','V','Z'};

const std::map<char, int> alfabeto_int2char_map = {{1,'A'},{2,'B'},{3,'C'},{4,'D'},{5,'E'},{6,'F'},{7,'G'},{8,'H'},{9,'I'},{10,'L'},{11,'M'},{12,'N'},{13,'O'},{14,'P'},{15,'Q'},{16,'R'},{17,'S'},{18,'T'},{19,'U'},{20,'V'}, {21,'Z'}};

const std::map<char, int> alfabeto_char2int_map = {{'A',1},{'B',2},{'C',3},{'D',4},{'E',5},{'F',6},{'G',7},{'H',8},{'I',9},{'L',10},{'M',11},{'N',12},{'O',13},{'P',14},{'Q',15},{'R',16},{'S',17},{'T',18},{'U',19},{'V',20}, {'Z',21},
										{'a',1},{'b',2},{'c',3},{'d',4},{'e',5},{'f',6},{'g',7},{'h',8},{'i',9},{'l',10},{'m',11},{'n',12},{'o',13},{'p',14},{'q',15},{'r',16},{'s',17},{'t',18},{'u',19},{'v',20}, {'z',21}};

/*
void flottaPrintGeneralePerSe(Giocatore & GIOCATORE)
{
	for(std::vector<Nave *>::const_iterator it = GIOCATORE.flottaOfGiocatoreGet().flottaOfFlottaGet().begin(); it < GIOCATORE.flottaOfGiocatoreGet().flottaOfFlottaGet().end(); ++it)
	{
		std::cout << " ";
		(**it).NavePrintPerSe();
	};
};
*/

int traduciCharAint(char CARATTERE)
{
	return alfabeto_char2int_map.find(CARATTERE)->second;
}

char traduciIntAChar(int INTERO)
{
	return alfabeto_int2char_map.find(INTERO)->second;
}

char controlloInputChar(char CARATTERE)
{
	while(!(std::cin >> CARATTERE) || !(std::find(alfabeto_maiuscolo_e_minuscolo.begin(), alfabeto_maiuscolo_e_minuscolo.end(), CARATTERE) != alfabeto_maiuscolo_e_minuscolo.end()))
	{
		std::cout << "Non hai inserito una lettera dell'alfabeto, riprova: " << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}
	return CARATTERE;
}

int controlloInputInt(int INTERO)
{
	while(!(std::cin >> INTERO))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Non hai inserito un intero, riprova:\n";
	}
	return INTERO;
}

int controlloInputDirezione(int DIREZIONE)
{
	std::vector<int> direzioni = {0,1};
	while(!(std::cin >> DIREZIONE) || !(std::find(direzioni.begin(), direzioni.end(), DIREZIONE) != direzioni.end()))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Non hai inserito una direzione valida, riprova:\n";
	}
	return DIREZIONE;
}

void flottaPrintGeneralePerAvversario(Giocatore & GIOCATORE) //per ora in realtà non c'è bisogno di una distinzione tra la flotta printata per l'avversario e quella per se
{
	for(std::vector<Nave *>::const_iterator it = GIOCATORE.flottaOfGiocatoreGet().flottaOfFlottaGet().begin(); it < GIOCATORE.flottaOfGiocatoreGet().flottaOfFlottaGet().end(); ++it)
	{
		std::cout << " ";
		(**it).NavePrintPerAvversario();
	};

	std::cout << std::endl;
};

void printGrigliaPerSe(Giocatore & GIOCATORE, int LATO)
{
	std::cout << "    ";

	for(int k = 1; k <= LATO; k++)
	{
		if(k < 10) std::cout << " " << traduciIntAChar(k) << " ";
		if(k >= 10) std::cout << " " << traduciIntAChar(k) << " ";
	}
	std::cout << std::endl;

	std::cout << "   ";
	for(int l = 0; l < LATO; l++)
	{
		std::cout << "___";
	}
	std::cout << "\n";

	for(int i = 1; i <= LATO; ++i)
	{
		if(i < 10) 	std::cout << "0" << i << "| ";
		if(i >= 10)	std::cout << i << "| ";

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
						std::cout << " x ";
						goto exit1
							;
					}
				};

				for(it2 = GIOCATORE.flottaOfGiocatoreGet().lista_punti_Nave_colpitiGet().begin(); it2 < GIOCATORE.flottaOfGiocatoreGet().lista_punti_Nave_colpitiGet().end(); ++it2)
				{
					if((*it2).ascissaGet() == i && (*it2).ordinataGet() == j)
					{
						std::cout << " C ";
						goto exit1;
					};
				};

				for(it3 = GIOCATORE.flottaOfGiocatoreGet().flottaOfFlottaGet().begin(); it3 < GIOCATORE.flottaOfGiocatoreGet().flottaOfFlottaGet().end(); ++it3)
				{
					for(it4 = (*it3)->lista_punti_occupatiGet().begin(); it4 < (*it3)->lista_punti_occupatiGet().end(); ++it4)
					{
						if((*it4).ascissaGet() == i && (*it4).ordinataGet() == j && (*it4).e_stato_colpitoGet() == false)
						{
							std::cout << " " << (*it3)->lunghezzaGet() << " ";
							goto exit1;
						};

						if((*it4).ascissaGet() == i && (*it4).ordinataGet() == j && (*it4).e_stato_colpitoGet() == true)
						{
							std::cout << " C ";
							goto exit1;
						};
					};
				};

				std::cout << " . ";

			exit1:
				{
				};
			};
		};
		std::cout << std::endl;
	};
	std::cout << std::endl;
};

void printGrigliaPerAvversario(Giocatore & GIOCATORE, int LATO)
{
	std::cout << "    ";

	for(int k = 1; k <= LATO; k++)
	{
		if(k < 10) std::cout << " " << traduciIntAChar(k) << " ";
		if(k >= 10) std::cout << " " << traduciIntAChar(k) << " ";
	}
	std::cout << std::endl;

	std::cout << "   ";
	for(int l = 0; l < LATO; l++)
	{
		std::cout << "___";
	}
	std::cout << "\n";

	for(int i = 1; i <= LATO; ++i)
	{
		if(i < 10) std::cout << "0" << i << "| ";
		if(i >= 10)	std::cout << i << "| ";

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
					std::cout << " x ";
					goto exit1;
				};
			};

			for(it2 = GIOCATORE.flottaOfGiocatoreGet().lista_punti_Nave_colpitiGet().begin(); it2 < GIOCATORE.flottaOfGiocatoreGet().lista_punti_Nave_colpitiGet().end(); ++it2)
			{
				if((*it2).ascissaGet() == i && (*it2).ordinataGet() == j)
				{
					std::cout << " C ";
					goto exit1;
				};
			};

			for(it3 = GIOCATORE.flottaOfGiocatoreGet().flottaOfFlottaGet().begin(); it3 < GIOCATORE.flottaOfGiocatoreGet().flottaOfFlottaGet().end(); ++it3)
			{
				for(it4 = (*it3)->lista_punti_occupatiGet().begin(); it4 < (*it3)->lista_punti_occupatiGet().end(); ++it4)
				{
					if((*it4).ascissaGet() == i && (*it4).ordinataGet() == j && (*it4).e_stato_colpitoGet() == false)
					{
						std::cout << " . ";
						goto exit1;
					};
					if((*it4).ascissaGet() == i && (*it4).ordinataGet() == j && (*it4).e_stato_colpitoGet() == true)
					{
						std::cout << " C ";
						goto exit1;
					};
				};

			};
			std::cout << " . ";
		exit1:
			{
			};
		};
		std::cout << std::endl;
	};
	std::cout << std::endl;
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
				std::cout << "Questo punto di mare e' gia' stato colpito. " << std::endl << std::endl;
				goto exit;
			};
		};

		for(it2 = GIOCATORE_DA_COLPIRE.flottaOfGiocatoreGet().lista_punti_Nave_colpitiGet().begin(); it2 < GIOCATORE_DA_COLPIRE.flottaOfGiocatoreGet().lista_punti_Nave_colpitiGet().end(); ++it2)
		{
			if((*it2).ascissaGet() == ASCISSA && (*it2).ordinataGet() == ORDINATA)
			{
				std::cout << "Questo punto di una nave e' gia' stato colpito. " << std::endl << std::endl;
				goto exit;
			};
		};


		for(it3 = GIOCATORE_DA_COLPIRE.flottaOfGiocatoreGet().flottaOfFlottaGet().begin(); it3 < GIOCATORE_DA_COLPIRE.flottaOfGiocatoreGet().flottaOfFlottaGet().end(); ++it3)
		{
			for(it4 = (*it3)->lista_punti_occupatiGet().begin(); it4 < (*it3)->lista_punti_occupatiGet().end(); ++it4)
			{
				if((*it4).ascissaGet() == ASCISSA && (*it4).ordinataGet() == ORDINATA)
				{
					std::cout << "hai colpito una nave di " << GIOCATORE_DA_COLPIRE.nome_giocatoreGet() << "!" << std::endl << std::endl;

					int temporary_local = ((*it3)->integritaGet());
					(*it3)->integritaSet(--temporary_local);
					(*it4).e_stato_colpitoSet(true);
					GIOCATORE_DA_COLPIRE.flottaOfGiocatoreGet().lista_punti_Nave_colpitiGet().push_back(punto_da_aggiungere);

					if((*it3)->integritaGet() == 0)
					{
						std::cout << "hai affondato " << (*it3)->nome_naveGet() << " di Giocatore " << GIOCATORE_DA_COLPIRE.nome_giocatoreGet() << "." << std::endl << std::endl;
						(*it3)->~Nave();
						*it3 = NULL;
						it3 = (GIOCATORE_DA_COLPIRE.flottaOfGiocatoreGet().flottaOfFlottaGet().erase(it3));
					}
					goto exit;
				};
			};
		};

		std::cout << "non hai colpito alcuna nave di" << GIOCATORE_DA_COLPIRE.nome_giocatoreGet() << "!" << std::endl << std::endl;
		GIOCATORE_DA_COLPIRE.flottaOfGiocatoreGet().lista_punti_mare_colpitiGet().push_back(punto_da_aggiungere);
	}

exit:
	{
	};
};

void scegliEColpisciPunto(Giocatore & GIOCATORE_IN_DIFESA)
{
	std::cout << "Fornisci le coordinate del punto che vuoi colpire. " << std::endl;

	int ascissa = 1;
	char ordinata = 'K';

	std::cout << "Ascissa: " << std::endl;
	ascissa = controlloInputInt(ascissa);
	std::cout << "Ordinata: " << std::endl;
	ordinata = controlloInputChar(ordinata);

	ColpisciPunto(ascissa, traduciCharAint(ordinata), GIOCATORE_IN_DIFESA);
};

void turno(Giocatore & GIOCATORE_IN_ATTACCO, Giocatore & GIOCATORE_IN_DIFESA, int LATO)
{
	std::cout << "-----------------------------------inizio turno di " << GIOCATORE_IN_ATTACCO.nome_giocatoreGet() << "------------------------------------" << std::endl;
	std::cout << "Giocatore " << GIOCATORE_IN_ATTACCO.nome_giocatoreGet() << ", e' il tuo turno di attaccare, questo e' cio' che vedi del tuo avversario: " << std::endl;

	printGrigliaPerAvversario(GIOCATORE_IN_DIFESA, LATO);

	std::cout << "Giocatore " << GIOCATORE_IN_ATTACCO.nome_giocatoreGet() << ", le navi non ancora affondate del tuo avversario sono: " << std::endl << std::endl;

	flottaPrintGeneralePerAvversario(GIOCATORE_IN_DIFESA);

	scegliEColpisciPunto(GIOCATORE_IN_DIFESA);

	if(!GIOCATORE_IN_DIFESA.flottaOfGiocatoreGet().flottaOfFlottaGet().empty())
	{
		std::cout << "Giocatori! Questo e' cio' che rimane della flotta di Giocatore " << GIOCATORE_IN_DIFESA.nome_giocatoreGet() << "\n" << std::endl;
		flottaPrintGeneralePerAvversario(GIOCATORE_IN_DIFESA);
	}

	if(GIOCATORE_IN_DIFESA.flottaOfGiocatoreGet().flottaOfFlottaGet().empty())
	{
		std::cout << GIOCATORE_IN_DIFESA.nome_giocatoreGet() << "non ha piu' navi" << std::endl;
	}

	std::cout << "Giocatore " << GIOCATORE_IN_DIFESA.nome_giocatoreGet() << ", questo e' cio' che vedi del tuo campo ora (non farlo vedere a" << GIOCATORE_IN_ATTACCO.nome_giocatoreGet() << "):" << std::endl;
	printGrigliaPerSe(GIOCATORE_IN_DIFESA, LATO);

	std::cout << "-----------------------------------fine turno di " << GIOCATORE_IN_ATTACCO.nome_giocatoreGet() << "------------------------------------" << std::endl;
	std::cout << std::endl;
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
	std::cout << "Giocatore " << GIOCATORE.nome_giocatoreGet() << ", ora e' il momento di posizionare le tue navi." << std::endl;

	std::vector<Nave *>::iterator it;
	for(it = GIOCATORE.flottaOfGiocatoreGet().flottaOfFlottaGet().begin(); it < GIOCATORE.flottaOfGiocatoreGet().flottaOfFlottaGet().end(); ++it)
	{
		std::cout << "Giocatore " << GIOCATORE.nome_giocatoreGet() << ", questo e' cio' che tu vedi del tuo campo: " << "\n" << std::endl;

		printGrigliaPerSe(GIOCATORE, LATO);

		std::cout << "Giocatore " << GIOCATORE.nome_giocatoreGet() << ", stai per posizionare " << (*it)->nome_naveGet() << " (lunghezza: " << (*it)->lunghezzaGet() << ")" << std::endl;
		std::cout << "Giocatore " << GIOCATORE.nome_giocatoreGet() << ", fornisci ascissa, ordinata e direzione in cui posizionare (0 per orizzonatale, 1 per verticale):" << std::endl;

		int ascissa = 1;
		char ordinata = 'K';
		bool direzione = 0;

		std::cout << "Ascissa: " << std::endl;
		ascissa = controlloInputInt(ascissa);
		std::cout << "Ordinata: " << std::endl;
		ordinata = controlloInputChar(ordinata);
		std::cout << "Direzione: " << std::endl;
		direzione = controlloInputDirezione(direzione);
		std::cout << std::endl;

		if(direzione == 0)
			for(int i = 0; i < (*it)->lunghezzaGet(); i++)
			{
				Punto puntolocal(ascissa, traduciCharAint(ordinata) + i, false);
				(*it)->lista_punti_occupatiGet().push_back(puntolocal);
			};


		if(direzione == 1)
			for(int i = 0; i < (*it)->lunghezzaGet(); i++)
			{
				Punto puntolocal(ascissa + i, traduciCharAint(ordinata), false);
				(*it)->lista_punti_occupatiGet().push_back(puntolocal);
			};
	};
	std::cout << "Giocatore " << GIOCATORE.nome_giocatoreGet() << ", questo e' il tuo campo a fine posizionamento: " << std::endl;

	printGrigliaPerSe(GIOCATORE, LATO);
};

void dichiarazioneVincitore(Giocatore & GIOCATORE1, Giocatore & GIOCATORE2)
{
	std::cout << "il vincitore di questa partita e' il giocatore ";
	if(GIOCATORE1.flottaOfGiocatoreGet().flottaOfFlottaGet().empty() && !GIOCATORE2.flottaOfGiocatoreGet().flottaOfFlottaGet().empty())
	{
		std::cout << GIOCATORE2.nome_giocatoreGet() << std::endl;
		int punteggiolocal = GIOCATORE2.punteggioGet();
		GIOCATORE2.punteggioSet(punteggiolocal++);

	};

	if(!GIOCATORE1.flottaOfGiocatoreGet().flottaOfFlottaGet().empty() && GIOCATORE2.flottaOfGiocatoreGet().flottaOfFlottaGet().empty())
	{
		std::cout << GIOCATORE1.nome_giocatoreGet() << std::endl;
		int punteggiolocal = GIOCATORE2.punteggioGet();
		GIOCATORE1.punteggioSet(punteggiolocal++);
	};

	if(GIOCATORE1.flottaOfGiocatoreGet().flottaOfFlottaGet().empty() && GIOCATORE2.flottaOfGiocatoreGet().flottaOfFlottaGet().empty()) std::cout << "la partita è finita in parità" << std::endl;
};

void partita(Giocatore & GIOCATORE1, Giocatore & GIOCATORE2, Flotta & FLOTTA_PER_GIOCATORE2, Flotta & FLOTTA_PER_GIOCATORE1, int LATO = 10)
{

	GIOCATORE1.flottaOfGiocatoreGet() = FLOTTA_PER_GIOCATORE1;
	GIOCATORE2.flottaOfGiocatoreGet() = FLOTTA_PER_GIOCATORE2;

	std::cout << std::endl << "-----------------------POSIZIONAMENTO GIOCATORE1:-----------------------" << std::endl;
	posizionamentoGiocatore(GIOCATORE1, LATO);

	std::cout << std::endl << "-----------------------POSIZIONAMENTO GIOCATORE2:-----------------------" << std::endl;
	posizionamentoGiocatore(GIOCATORE2, LATO);

	std::cout << std::endl << "-----------------------COMINCIA LA BATTAGLIA!-----------------------" << std::endl;
	battaglia(GIOCATORE1, GIOCATORE2, LATO);

	dichiarazioneVincitore(GIOCATORE1, GIOCATORE2);
};

