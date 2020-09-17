/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L02_T2
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 14.9.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>

int main() {
    int nLuku1 = 0;
    int nLuku2 = 0;
    int nValinta = 0;

    printf("Anna kaksi kokonaislukua: ");
    scanf("%d %d", &nLuku1, &nLuku2);

    printf("\n");
    printf("Valikko\n");
    printf("1) Summaa luvut yhteen.\n");
    printf("2) Kerro luvut keskenään.\n");
    printf("Valitse: ");
    scanf("%d", &nValinta);
    printf("\n");

    if(nValinta == 1){
        printf("Luvut laskettiin yhteen. Tulos = %d.\n", nLuku1 + nLuku2);
    } else if (nValinta == 2){
        printf("Luvut kerrottiin keskenään. Tulos = %d.\n", nLuku1 * nLuku2);
    } else {
        printf("Tuntematon valinta.\n");
    }
    return 0;
}
/*******************************************************************/
/* eof */