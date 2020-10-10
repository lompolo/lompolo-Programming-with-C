/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L07_T2: program.c
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 10.10.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>
//#include <stdlib.h>
#include "lista.h"

enum Boolean {FALSE, TRUE};

int paavalikko() {
    int valinta;
    printf("1) Luo lista\n");
    printf("2) Lisää alkio listan loppuun\n");
    printf("3) Lisää alkio listan keskelle\n");
    printf("4) Tyhjennä lista\n");
    printf("5) Poista alkio listasta\n");
    printf("6) Tulosta lista\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi: ");
    scanf("%d", &valinta);

    return valinta;
}

int listanPituus(){
    int pituus;

    printf("Anna listan pituus: ");
    scanf("%d", &pituus);

    if (pituus < 0)
    {
        printf("Listan pituus ei voi olla negatiivinen.\n");
        pituus = -1;
    }
    
    return pituus;
}

int main() {
    Alkio *alku = NULL;
    int jatka = TRUE;
    int valinta = 0, pituus = 0, luku = 1, paikka = 0;

    printf("Tämä ohjelma hallitsee listaa ja sen alkioita.\n");

    while (jatka)
    {
        valinta = paavalikko();
        switch (valinta)
        {
        case 0:
            jatka = FALSE;
            alku = tyhjennaLista(alku);
            printf("Kiitos ohjelman käytöstä.\n");
            break;

        case 1:
            pituus = listanPituus();

            if (pituus == -1)
                break;

            alku = luoLista(alku, pituus, luku);
            tulostaLista(alku);
            luku += pituus;
            break;

        case 2:
            alku = lisaaLoppuun(alku, luku);
            tulostaLista(alku);
            luku++;
            break;

        case 3:
            printf("Monenneksi solmuksi alkio lisätään: ");
            scanf("%d", &paikka);
            if (paikka < 1)
                printf("Antamasi luku ei ole kelvollinen.\n");
            alku = lisaaListaan(alku, paikka, luku);
            luku++;
            break;

        case 4:
            alku = tyhjennaLista(alku);
            break;

        case 5:
            printf("Monesko solmu poistetaan: ");
            scanf("%d", &paikka);
            if (paikka < 1)
                printf("Antamasi luku ei ole kelvollinen.\n");
            
            alku = poistaListalta(alku, paikka);
            break;

        case 6:
            tulostaLista(alku);
            break;

        default:
            printf("Tuntematon valinta, yritä uudestaan.\n");
        }
    }
    
    return 0;
}
/*******************************************************************/
/* eof */
/*******************************************************************/