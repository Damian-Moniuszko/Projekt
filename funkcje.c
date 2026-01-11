#include "wynalazek.h"

void wyswietlMenu() {
    printf("\n--- KARTOTEKA PROFESORA VON WUNDERWERK ---\n");
    printf("1. Dodaj nowy wynalazek\n");
    printf("2. Wyswietl wszystkie wynalazki\n");
    printf("3. Edytuj wynalazek\n");
    printf("4. Usun wynalazek\n");
    printf("5. Szukaj/Sortuj\n");
    printf("6. Zapisz i Wyjdz\n");
    printf("Wybor: ");
}

Wezel* stworzNowyWezel(){
    Wezel* nowy = (Wezel*)malloc(sizeof(Wezel));

    if (nowy == NULL) {
        printf("Brak pamieci!\n");
        return NULL;
    }

    nowy->nastepny = NULL;

    return nowy;
}

void dodajWynalazek(Wezel** glowa) {
    Wezel* nowy = stworzNowyWezel();
    if (nowy == NULL) {
        return;
    }

    printf("---DODAWANIE WYNALAZKU---\n");

    printf("Podaj nazwe wynalazku: ");
    scanf("%100s", nowy->dane.nazwa);

    printf("Podaj typ wynalazku: ");
    scanf("%50s", nowy->dane.typ);

    printf("Podaj niezawodnosc (0-100): ");
    scanf("%d", &nowy->dane.niezawodnosc);

    printf("Podaj zapotrzebowanie na energie: ");
    scanf("%f", &nowy->dane.zapotrzebowanieEnergii);

    nowy->dane.status = PROTOTYP;

    nowy->nastepny = *glowa;
    *glowa = nowy;

    printf("Wynalazek dodany pomyslnie!\n");
}

void wyswietlWynalazki(Wezel* glowa) {
    if (glowa == NULL) {
        printf("Brak wynalazkow w kartotece.\n");
        return;
    }

    printf("\n--- LISTA WYNALAZKOW ---\n");

    Wezel* aktualny = glowa;
    while (aktualny != NULL) {
        printf("Nazwa: %s\n", aktualny->dane.nazwa);
        printf("Typ: %s\n", aktualny->dane.typ);
        printf("Niezawodnosc: %d\n", aktualny->dane.niezawodnosc);
        printf("Zapotrzebowanie na energie: %.2f\n", aktualny->dane.zapotrzebowanieEnergii);
        printf("Status: %d\n", aktualny->dane.status);
        printf("-------------------------\n");
        aktualny = aktualny->nastepny;
    }
}