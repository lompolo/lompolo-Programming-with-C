/*******************************************************************/
/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L07_T3: io.h
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 11.10.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "io.h"

void arvoNumerot(int *taulukko, int maara){
    srand(40);
    int luku = 0, t = 0, i = 0;

    while (i < maara)
    {
        luku = (rand()%((NO_MAX - NO_MIN) + 1));
        t = tarkistaNumero(taulukko, luku, i+1);
        if (t == 0){
            taulukko[i] = luku;
            i++;
        }
    }
}

int tarkistaNumero(int *taulukko, int numero, int maara){    
    for (int i = 0; i < maara; i++)
    {
        if (taulukko[i] == numero)
            return 1;
    }

    return 0;
}

void tulostaNumerot(int *taulukko, int maara){    
    for (int i = 0; i < maara; i++)
    {
        printf("%d ", taulukko[i]);
    }
    printf("\n");
}

/*******************************************************************/
/* eof */