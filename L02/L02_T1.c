/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L02_T1
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 14.9.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>

int main() {
    int nLuku = 0;

    printf("Anna jokin luku väliltä 10 - 200: ");
    scanf("%d", &nLuku);

    if(nLuku < 10 || nLuku > 200){
        printf("Antamasi luku ei ole annetulla välillä.\n");
    } else {
        int nSumma = 0;
        for(int i = 0; i <= nLuku; i++)
            nSumma += i;
        printf("Lukujen 0 - %d summa on %d.\n", nLuku, nSumma);
    }

    return 0;
}
/*******************************************************************/
/* eof */