#ifndef WYNALAZEK_H
#define WYNALAZEK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    PROTOTYP,
    W_TESTACH,
    DOPUSZCZONY,
    ZAKAZANY,
    NIESTABILNY
} StatusWynalazku;

typedef struct {
    char nazwa[101];
    char typ[51];
    int niezawodnosc;
    float zapotrzebowanieEnergii;
    StatusWynalazku status;
} Wynalazek;

typedef struct Wezel {
    Wynalazek dane;
    struct Wezel* nastepny;
} Wezel;

void wyswietlMenu();
void dodajWynalazek(Wezel** glowa);
void wyswietlWynalazki(Wezel* glowa);

#endif