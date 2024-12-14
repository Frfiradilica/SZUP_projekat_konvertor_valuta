#include <stdio.h>

int main() {
    printf("Dobrodošli u konvertor valuta!\n");

    double kurs[3][3] = {
        {1.0, 117.5, 0.85},
        {0.0085, 1.0, 0.0072},
        {1.18, 138.0, 1.0}
    };

    printf("Kursna lista dodata za osnovne valute (EUR, RSD, USD).\n");
    return 0;
}
