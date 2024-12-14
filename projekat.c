#include <stdio.h>

void ucitajKurs(double kurs[3][3], const char* nazivFajla) {
    FILE* fajl = fopen(nazivFajla, "r");
    if (fajl == NULL) {
        printf("Greška pri otvaranju datoteke!\n");
        return;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            fscanf(fajl, "%lf", &kurs[i][j]);
        }
    }
    fclose(fajl);
}

double konvertuj(double iznos, int izValute, int uValutu, double kurs[3][3]) {
    return iznos * kurs[izValute - 1][uValutu - 1];
}

int main() {
    printf("Dobrodošli u konvertor valuta!\n");

    double kurs[3][3];
    ucitajKurs(kurs, "kursna_lista.txt");

    int izValute, uValutu;
    double iznos;

    printf("Unesite iznos: ");
    scanf("%lf", &iznos);

    printf("Unesite valutu iz koje konvertujete (1-EUR, 2-RSD, 3-USD): ");
    scanf("%d", &izValute);

    printf("Unesite valutu u koju konvertujete (1-EUR, 2-RSD, 3-USD): ");
    scanf("%d", &uValutu);

    double rezultat = konvertuj(iznos, izValute, uValutu, kurs);
    printf("Rezultat: %.2f\n", rezultat);

    return 0;
}
