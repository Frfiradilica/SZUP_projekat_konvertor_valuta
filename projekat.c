#include <stdio.h>

int main() {
    printf("Dobrodošli u konvertor valuta!\n");

    double kurs[3][3] = {
        {1.0, 117.5, 0.85},
        {0.0085, 1.0, 0.0072},
        {1.18, 138.0, 1.0}
    };

    int izValute, uValutu;
    double iznos, rezultat;

    printf("Unesite iznos: ");
    scanf("%lf", &iznos);

    printf("Unesite valutu iz koje konvertujete (1-EUR, 2-RSD, 3-USD): ");
    scanf("%d", &izValute);

    printf("Unesite valutu u koju konvertujete (1-EUR, 2-RSD, 3-USD): ");
    scanf("%d", &uValutu);

    rezultat = iznos * kurs[izValute - 1][uValutu - 1];
    printf("Rezultat: %.2f\n", rezultat);

    return 0;
}
