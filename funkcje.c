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

void zapiszDoPliku(Wezel* glowa, const char* nazwaPliku) {
    FILE* plik = fopen(nazwaPliku, "w");
    if (plik == NULL) {
        printf("Nie mozna otworzyc pliku do zapisu.\n");
        return;
    }

    Wezel* aktualny = glowa;
    while (aktualny != NULL) {
        fprintf(plik, "%s %s %d %.2f %d\n",
                aktualny->dane.nazwa,
                aktualny->dane.typ,
                aktualny->dane.niezawodnosc,
                aktualny->dane.zapotrzebowanieEnergii,
                aktualny->dane.status);
        aktualny = aktualny->nastepny;
    }

    fclose(plik);
    printf("Dane zapisane pomyslnie do pliku %s\n", nazwaPliku);
}

void wczytajZPliku(Wezel** glowa, const char* nazwaPliku) {
    FILE* plik = fopen(nazwaPliku, "r");
    if (plik == NULL) {
        printf("Nie mozna otworzyc pliku do odczytu.\n");
        return;
    }

    Wynalazek tymczasowy;
    int statusInt;

    while (fscanf(plik, "%100s %50s %d %f %d",
            tymczasowy.nazwa,
            tymczasowy.typ,
            &tymczasowy.niezawodnosc,
            &tymczasowy.zapotrzebowanieEnergii,
            &statusInt) == 5) {

        tymczasowy.status = (StatusWynalazku)statusInt;

        Wezel* nowy = stworzNowyWezel();
        if (nowy != NULL) {
            nowy->dane = tymczasowy;
            nowy->nastepny = *glowa;
            *glowa = nowy;
        }
    }

    fclose(plik);
    printf("Dane wczytane pomyslnie z pliku %s\n", nazwaPliku);
}

void edytujWynalazek(Wezel* glowa) {
    if (glowa == NULL) {
        printf("Brak wynalazkow do edycji.\n");
        return;
    }

    char szukanaNazwa[101];
    printf("Podaj nazwe wynalazku do edycji: ");
    scanf("%100s", szukanaNazwa);

    Wezel* aktualny = glowa;
    while (aktualny != NULL) {
        if (strcmp(aktualny->dane.nazwa, szukanaNazwa) == 0){
            printf("Edycja wynalazku: %s\n", aktualny->dane.nazwa);

            printf("Podaj nowy typ wynalazku: ");
            scanf("%50s", aktualny->dane.typ);

            printf("Podaj nowa niezawodnosc (0-100): ");
            scanf("%d", &aktualny->dane.niezawodnosc);

            printf("Podaj nowe zapotrzebowanie na energie: ");
            scanf("%f", &aktualny->dane.zapotrzebowanieEnergii);

            printf("Wynalazek zaktualizowany pomyslnie!\n");
            return;
        }
        aktualny = aktualny->nastepny;
    }
    printf("Nie znaleziono wynalazku o podanej nazwie.\n");
}

void usunWynalazek(Wezel** glowa){
    if (*glowa == NULL) {
        printf("Brak wynalazkow do usuniecia.\n");
        return;
    }
    
    char szukanaNazwa[101];
    printf("Podaj nazwe wynalazku do usuniecia: ");
    scanf("%100s", szukanaNazwa);

    Wezel* aktualny = *glowa;
    Wezel* poprzedni = NULL;

    while (aktualny != NULL && strcmp(aktualny->dane.nazwa, szukanaNazwa) != 0) {
        poprzedni = aktualny;
        aktualny = aktualny->nastepny;
    }

    if (aktualny == NULL) {
        printf("Nie znaleziono wynalazku o podanej nazwie.\n");
        return;
    }

    if (poprzedni == NULL) {
        *glowa = aktualny->nastepny;
    } else {
        poprzedni->nastepny = aktualny->nastepny;
    }

    free(aktualny);
    printf("Wynalazek usuniety pomyslnie!\n");
}