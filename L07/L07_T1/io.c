/*******************************************************************/
/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L07_T1: oi.c
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 9.10.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TIEDOSTO "askeldata.txt"
#define MAX_LEN 20

int lue_askeleet_listaan(int *lista, int koko){
    FILE * tiedosto = NULL;
    char rivi[MAX_LEN];
    int laskuri = 0, summa = 0;

    if((tiedosto = fopen(TIEDOSTO, "r")) == NULL){
        fprintf(stderr, "Tiedoston avaus epäonnistui.\n");
        exit(0);
    }

    while (fgets(rivi, MAX_LEN, tiedosto) != NULL || laskuri < koko)
    {
        strtok(rivi, ":");
        lista[laskuri] = atoi(strtok(NULL, "\n"));
        summa += lista[laskuri];
        laskuri++;
    }

    fclose(tiedosto);

    return summa;
}

void tulosta_lista(int *lista, int koko){
    printf("Listan askeleet: ");
    for (int i = 0; i < koko; i++)
    {
        printf("%d ", lista[i]);
    }
    printf("\n");
    
}
/*******************************************************************/
/* eof */