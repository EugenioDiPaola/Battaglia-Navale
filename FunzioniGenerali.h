#ifndef FUNZIONIGENERALI_H
#define FUNZIONIGENERALI_H

#include"Giocatore.h"

void flottaPrintGeneralePerSe(Giocatore & GIOCATORE);
void flottaPrintGeneralePerAvversario(Giocatore & GIOCATORE);
void printGrigliaPerSe(Giocatore & GIOCATORE, int LATO);
void printGrigliaPerAvversario(Giocatore & GIOCATORE, int LATO);
void ColpisciPunto(int ASCISSA, int ORDINATA, Giocatore & GIOCATORE_DA_COLPIRE);
void scegliEColpisciPunto(Giocatore & GIOCATORE_IN_DIFESA);
void turno(Giocatore & GIOCATORE_IN_ATTACCO, Giocatore & GIOCATORE_IN_DIFESA, int LATO);
bool viEUnVincitoreTra(Giocatore & GIOCATORE1, Giocatore & GIOCATORE2);
void battaglia(Giocatore & GIOCATORE1, Giocatore & GIOCATORE2, int LATO);
void posizionamentoGiocatore(Giocatore & GIOCATORE, int LATO);
void dichiarazioneVincitore(Giocatore & GIOCATORE1, Giocatore & GIOCATORE2);
void partita(Giocatore & GIOCATORE1, Giocatore & GIOCATORE2, Flotta & FLOTTA_PER_GIOCATORE2, Flotta & FLOTTA_PER_GIOCATORE1, int);

#endif
