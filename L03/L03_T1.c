/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L03_T1
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 17.9.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>

int toPower(int, int);

int main() {
    int nLuku;
    int nPotenssi;

    printf("Ohjelma laskee luvun potenssin.\n");
    printf("Anna kokonaisluku, jonka haluat korottaa potenssiin: ");
    scanf("%d", &nLuku);
    printf("Anna potenssi, jonka haluat laskea: ");
    scanf("%d", &nPotenssi);
    printf("%d ^ %d = %d.\n", nLuku, nPotenssi, toPower(nLuku, nPotenssi));
    return 0;
}

int toPower(int x, int power) {
    int result = 1;
    for (int i = 1; i <= power; i++)
    {
        result *= x;
    }
    return result;
}
/*******************************************************************/
/* eof */