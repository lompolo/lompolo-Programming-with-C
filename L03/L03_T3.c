/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L03_T3
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 27.9.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>
#include <string.h>

void longCompare(long, long);
void doubleCompare(double, double);
void stringCompare(char*, char*);

int main() {
    int nLuku1, nLuku2;
    float fLuku1, fLuku2;
    char sNimi1[100]; 
    char sNimi2[100];

    printf("Anna kaksi kokonaislukua:\n");
    printf("Luku 1: ");
    scanf("%d", &nLuku1);
    printf("Luku 2: ");
    scanf("%d", &nLuku2);
    longCompare((long) nLuku1, (long) nLuku2);

    printf("Anna kaksi desimaalilukua:\n");
    printf("Luku 1: ");
    scanf("%f", &fLuku1);
    printf("Luku 2: ");
    scanf("%f", &fLuku2);
    doubleCompare((double) fLuku1, (double) fLuku2);

    printf("Anna kaksi nimeä:\n");
    printf("Nimi 1: ");
    scanf("%s", sNimi1);
    printf("Nimi 2: ");
    scanf("%s", sNimi2);
    stringCompare(sNimi1, sNimi2);
    return 0;
}

void longCompare(long num1, long num2){
    if(num1 > num2){
        printf("Luku %ld on suurempi ja %ld pienempi.\n", num1, num2);
    } else if (num1 < num2){
        printf("Luku %ld on suurempi ja %ld pienempi.\n", num2, num1);
    } else {
        printf("Luvut %ld ja %ld ovat yhtä suuria.\n", num1, num2);
    }
}

void doubleCompare(double num1, double num2){
    if(num1 > num2){
        printf("Luku %5.2lf on suurempi ja %5.2lf pienempi.\n", num1, num2);
    } else if (num1 < num2){
        printf("Luku %5.2lf on suurempi ja %5.2lf pienempi.\n", num2, num1);
    } else {
        printf("Luvut %5.2lf ja %5.2lf ovat yhtä suuria.\n", num1, num2);
    }
}

void stringCompare(char *string1, char *string2){
    int value = strcmp(string1, string2);

    if(value == 0){
        printf("Merkkijonona '%s' ja '%s' ovat yhtä suuria.\n", string1, string2);
    } else if (value < 0){
        printf("Merkkijonona '%s' on suurempi ja '%s' pienempi.\n", string2, string1);
    } else {
        printf("Merkkijonona '%s' on suurempi ja '%s' pienempi.\n", string1, string2);
    }
}
/*******************************************************************/
/* eof */