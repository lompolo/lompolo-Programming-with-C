/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L04_T1
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 28.9.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>
#include <string.h>

#define MAX 50

struct kirja
{
    char kirjan_nimi[MAX];
    int painovuosi;
    int hyllypaikka;
};


int main() {
    struct kirja Kirja; 
    
    printf("Anna kirjan nimi: ");
    fgets(Kirja.kirjan_nimi, MAX, stdin);
    printf("Anna kirjan painovuosi: ");
    scanf("%d", &(Kirja.painovuosi));
    printf("Anna kirjan hyllypaikka: ");
    scanf("%d", &(Kirja.hyllypaikka));

    Kirja.kirjan_nimi[strlen(Kirja.kirjan_nimi)-1] = '\0';

    printf("Kirjan nimi on '%s', painovuosi %d ja hyllypaikka %d.\n", Kirja.kirjan_nimi, Kirja.painovuosi, Kirja.hyllypaikka);
}
/*******************************************************************/
/* eof */