/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L05_T1
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 1.10.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>
#include <stdlib.h>

int nelio(int luku){
    return luku * luku;
}

int main(int argc, char *argv[]) {
    int luku;

    if (argc < 2)
    {
        perror("Et antanut lukua!");
        exit(1);
    }

    luku = atoi(argv[1]);

    printf("Luku on %d.\n", luku);
    printf("Luvun neliö on %d.\n", nelio(luku));

    return 0;
}
/*******************************************************************/
/* eof */