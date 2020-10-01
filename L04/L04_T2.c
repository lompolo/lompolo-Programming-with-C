/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L04_T2
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 28.9.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>

unsigned long fibbonacci(unsigned long luku){
    if (luku == 0)
    {
        return 0;
    } else if (luku == 1){
        return 1;
    } else {
        return fibbonacci(luku - 1) + fibbonacci(luku - 2);
    }
}

int main() {
    unsigned long luku;

    printf("Anna luku, jolle lasketaan Fibonaccin luku: ");
    scanf("%lu", &luku);
    printf("Luvun %lu Fibonaccin luku on %lu.\n", luku, fibbonacci(luku));
}
/*******************************************************************/
/* eof */