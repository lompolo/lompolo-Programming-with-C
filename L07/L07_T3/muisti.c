/*******************************************************************/
/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L07_T3: muisti.c
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 11.10.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>
#include <stdlib.h>

int* varaaMuistiaNumeroille(int maara){
    int *p = NULL;

    if ((p = (int *)malloc(maara*sizeof(int))) == NULL)
    {
        perror("Muistin varaus epäonnistui!");
        exit(0);
    }

    for(int i = 0; i < maara; i++){
		p[i] = 99;
	}
    
    return p;
}

void vapautaMuisti(int *taulukko){
    free(taulukko);
}

/*******************************************************************/
/* eof */