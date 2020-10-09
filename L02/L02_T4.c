/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L02_T4
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 16.9.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>

#define PII 3.141

int main() {
    float fLuku = 0.0;
    int nValinta = 0;

    printf("Anna liukuluku: ");
    scanf("%f", &fLuku);
    printf("\n");
    printf("Valikko\n");
    printf("1) Kerro piin arvo luvulla %.3f.\n", fLuku);
    printf("2) Jaa piin arvo luvulla %.3f.\n", fLuku);
    printf("Valitse: ");
    scanf("%d", &nValinta);
    printf("\n");

    switch (nValinta){
        case 1:
            printf("Pii * %.3f = %.3f.\n", fLuku, (PII * fLuku));
            break;
        case 2:
            printf("Pii / %.3f = %.3f.\n", fLuku, (PII / fLuku));
            break;    
        default:
            printf("Tuntematon valinta.\n");
            break;
    }

    return 0;
}
/*******************************************************************/
/* eof */