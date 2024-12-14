#include <stdio.h>

#define BROJ_VALUTA 6

void ucitajKurs(double kurs[BROJ_VALUTA][BROJ_VALUTA], const char* nazivFajla) {
    FILE* fajl = fopen(nazivFajla, "r");
    if (fajl == NULL) {
        printf("Greška pri otvaranju datoteke!\n");
        return;
    }
    for (int i = 0; i < BROJ_VALUTA; i++) {
        for (int j = 0; j < BROJ_VALUTA; j++) {
            fscanf(fajl, "%lf", &kurs[i][j]);
        }
    }
    fclose(fajl);
}

double konvertuj(double iznos, int izValute, int uValutu, double kurs[BROJ_VALUTA][BROJ_VALUTA]) {
    return iznos * kurs[izValute - 1][uValutu - 1];
}

int main() {
    printf("Dobrodošli u konvertor valuta!\n");

    double kurs[BROJ_VALUTA][BROJ_VALUTA];
    ucitajKurs(kurs, "kursna_lista.txt");

    int izValute, uValutu;
    double iznos;

    printf("Unesite iznos: ");
    scanf("%lf", &iznos);

    printf("Unesite valutu iz koje konvertujete (1-EUR, 2-RSD, 3-USD, 4-GBP, 5-CHF, 6-JPY): ");
    scanf("%d", &izValute);

    printf("Unesite valutu u koju konvertujete (1-EUR, 2-RSD, 3-USD, 4-GBP, 5-CHF, 6-JPY): ");
    scanf("%d", &uValutu);

    if (izValute < 1 || izValute > BROJ_VALUTA || uValutu < 1 || uValutu > BROJ_VALUTA) {
        printf("Greška: neispravan izbor valute!\n");
        return 1;
    }

    double rezultat = konvertuj(iznos, izValute, uValutu, kurs);
    printf("Rezultat: %.2f\n", rezultat);

    return 0;
}
