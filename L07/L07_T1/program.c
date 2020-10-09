/*******************************************************************/
/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L07_T1: program.c
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 9.10.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>
#include "io.h"

#define KOKO 10

int main() {
    int lista[KOKO];
    int koko = KOKO, summa = 0;

    printf("Askelanalyysi\n");
    summa = lue_askeleet_listaan(lista, koko);
    tulosta_lista(lista, koko);
    printf("Askelia yhteensä: %d\n", summa);
    return 0;
}
/*******************************************************************/
/* eof */