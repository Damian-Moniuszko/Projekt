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

    wyswietlMenu();

    return 0;
}