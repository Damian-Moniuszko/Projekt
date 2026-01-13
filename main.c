#include "wynalazek.h"

int main(int argc, char* argv[]){
    if (argc != 2) {
        printf("Blad! Nie podano nazwy pliku z danymi.\n");
        return 1;
    }

    char* nazwaPliku = argv[1];

    printf("Witaj, Profesorze von Wunderwerk!\n");
    printf("Wczytywanie kartoteki z pliku: %s\n", nazwaPliku);

    Wezel* pierwszyWynalazek = NULL;

    wczytajZPliku(&pierwszyWynalazek, nazwaPliku);

    int wybor;
    do {
        wyswietlMenu();

        if (scanf("%d", &wybor) != 1) {
            printf("Nieprawidlowy wybor. Sprobuj ponownie.\n");
            while (getchar() != '\n');
            wybor = 0;
            continue;
        }

        switch (wybor)
        {
        case 1:
            dodajWynalazek(&pierwszyWynalazek);
            break;

        case 2:
            wyswietlWynalazki(pierwszyWynalazek);
            break;

        case 3:
            edytujWynalazek(pierwszyWynalazek);
            break;

        case 4:
            usunWynalazek(&pierwszyWynalazek);
            break;
            
        case 6:
            zapiszDoPliku(pierwszyWynalazek, nazwaPliku);
            break;
        
        default:
            break;
        }
    } while (wybor != 6);

    return 0;
}