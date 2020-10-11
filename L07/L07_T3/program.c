/*******************************************************************/
/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L07_T3: program.c
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 9.10.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>
#include "io.h"
#include "muisti.h"

int main() {
    int lMaara = 0, vMaara = 0;
    int *lottonumerot = NULL, *varanumerot = NULL;
    printf("Lottoarvonta\n");
    printf("Kuinka monta numeroa arvotaan: ");
    scanf("%d", &lMaara);

    lottonumerot = varaaMuistiaNumeroille(lMaara);
    arvoNumerot(lottonumerot, lMaara);

    printf("Kuinka monta lisänumeroa arvotaan: ");
    scanf("%d", &vMaara);

    varanumerot = varaaMuistiaNumeroille(vMaara);
    arvoNumerot(varanumerot, vMaara);

    printf("Arvottiin seuraavat numerot ja lisänumerot.\n");
    printf("Numerot: ");
    tulostaNumerot(lottonumerot, lMaara);
    printf("Lisänumerot: ");
    tulostaNumerot(varanumerot, vMaara);

    return 0;
}
/*******************************************************************/
/* eof */