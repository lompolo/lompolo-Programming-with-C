/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L07_T2: lista.c
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 10.10.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Alkio *luoSolmu(Alkio *alku, int luku){
    Alkio *p = (Alkio*)malloc(sizeof(Alkio));

    /* Create new node */

    if(p == NULL){
        fprintf(stderr, "Muistinvaraus epäonnistui.\n");
        exit(0);
    };

    p->luku = luku;
    p->seuraava = NULL;

    return p;
}

Alkio *lisaaLoppuun(Alkio *alku, int luku){
    Alkio *p = NULL, *tmp = alku;

    /* Create new node */

    p = luoSolmu(alku, luku);

    /*Find last node */

    if (tmp != NULL)
    {
        while (tmp->seuraava != NULL)
            tmp = tmp->seuraava;
    }

    if (alku == NULL)
        alku = p;
    else
        tmp->seuraava = p;

    return alku;
}

Alkio *tyhjennaLista(Alkio *alku){
    Alkio *p = alku;
    while (p != NULL)
    {
        alku = p->seuraava;
        free(p);
        p = alku;
    };

    alku = NULL;

    return alku;
}

void tulostaLista(Alkio *alku){
    Alkio *p = alku;

    if (p == NULL)
        printf("\n");
    else {
         while (p != NULL)
        {
            printf("%d ", p->luku);
            p = p->seuraava;
        }
        printf("\n");
    }
}

Alkio *luoLista(Alkio *alku, int pituus, int ensimmainen){
    if (alku != NULL)
    {
        alku = tyhjennaLista(alku);
    }

    for (int i = ensimmainen; i < (ensimmainen + pituus); i++)
    {
        alku = lisaaLoppuun(alku, i);
    }

    return alku;
}

Alkio *haeSolmu(Alkio *alku, int paikka){
    Alkio *p = alku;
    int laskuri = 1;

    if (p != NULL)
    {
        while (p->seuraava != NULL && laskuri < paikka){
            p = p->seuraava;
            laskuri++;
        }
    }
    return p;
}

Alkio *lisaaListaan(Alkio *alku, int paikka, int luku){
    Alkio *p = NULL, *edellinen = alku, *jalkimmainen = NULL;

    if (alku == NULL)
    {
        alku = lisaaLoppuun(alku, luku);
    } else {
        p = luoSolmu(alku, luku);

        /* Hae paikkaa edeltävä solmu */
        if (paikka == 1)
        {
            p->seuraava = alku;
            alku = p;
        } else {
            edellinen = haeSolmu(alku, (paikka-1));
            jalkimmainen = edellinen->seuraava;
            edellinen->seuraava = p;
            p->seuraava = jalkimmainen;
        }
    }
    tulostaLista(alku);
    return alku;
}

Alkio *poistaListalta(Alkio *alku, int paikka){
    Alkio *p = NULL, *edellinen = alku, *jalkimmainen = NULL;

    if (alku == NULL)
        return NULL;
    
     /* Hae paikkaa edeltävä solmu */
     if(paikka == 1){
         jalkimmainen = alku->seuraava;
         p = alku;
         alku = jalkimmainen;
     } else {
         edellinen = haeSolmu(alku, (paikka-1));
        p = edellinen->seuraava;
        jalkimmainen = p->seuraava;
        edellinen->seuraava = jalkimmainen;
     }
     
    p->seuraava = NULL;
    free(p);
    p = NULL;

    return alku;
}

/*******************************************************************/
/* eof */
/*******************************************************************/