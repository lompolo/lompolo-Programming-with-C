/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L01_T4
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 14.9.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/

#include <stdio.h>

int main() {
    char charInput;
    char stringInput[20];

    printf("Anna merkki: ");
    scanf("%c", &charInput);
     printf("Annoit merkin ’%c’.\n", charInput);
    printf("Anna korkeintaan 20 merkkiä pitkä merkkijono: ");
    scanf("%s", stringInput);
    printf("Annoit merkkijonon ’%s’.\n", stringInput);
}

/*******************************************************************/
/* eof */