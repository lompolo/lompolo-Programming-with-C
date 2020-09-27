/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L03_T4
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 27.9.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>
#include <string.h>

#define MAX 30

void strCopy(char* dest, const char* source);

int main() {
    char merkkijono1[MAX];
    char merkkijono2[MAX];

    printf("Anna ensimmäinen merkkijono: ");
    fgets(merkkijono1, MAX, stdin);
    merkkijono1[strlen(merkkijono1)-1] = '\0';
    strCopy(merkkijono2, merkkijono1);

    printf("Merkkijono 1 on '%s'.\n", merkkijono1);
    printf("Merkkijono 2 on '%s'.\n", merkkijono2);
    return 0;
}

void strCopy(char* dest, const char* source){
    int i;
    for(i = 0; i < strlen(source); ++i){
        dest[i] = source[i];
    }
    dest[i] = '\0';
}
/*******************************************************************/
/* eof */