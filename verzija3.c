#include <stdio.h>

int main() {
    printf("Dobrodošli u konvertor valuta!\n");

    double kurs[3][3] = {
        {1.0, 117.5, 0.85},
        {0.0085, 1.0, 0.0072},
        {1.18, 138.0, 1.0}
    };

    int izbor;
    printf("Unesite broj za validaciju testa funkcionalnosti (1-3): ");
    scanf("%d", &izbor);

    if (izbor >= 1 && izbor <= 3) {
        printf("Unos je validan.\n");
    } else {
        printf("Unos nije validan.\n");
    }

    return 0;
}
