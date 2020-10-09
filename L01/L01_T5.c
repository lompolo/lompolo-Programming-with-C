/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L01_T5
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 14.9.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/

#include <stdio.h>

int main() {
    char fName[20];
    char lName[20];
    int age;
    float weight;

    printf("Anna etunimesi: ");
    scanf("%s", fName);
    printf("Anna sukunimesi: ");
    scanf("%s", lName);
    printf("Anna ikäsi: ");
    scanf("%d", &age);
    printf("Anna painosi: ");
    scanf("%f", &weight);
    printf("Nimesi on %s %s, ikäsi on %d vuotta ja painat %.1f kg.\n", fName, lName, age, weight);
}

/*******************************************************************/
/* eof */