/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L02_T3
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 15.9.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>

int main() {
    int counter = 0;

    printf("Anna jokin kokonaisluku väliltä 1-10: ");
    scanf("%d", &counter);

    if (counter < 1 || counter > 10){
        printf("Antamasi luku ei ole välillä 1-10.\n");
    } else {
        int i = 1;
        while (i <= counter)
        {
            printf("%d kierros.\n", i);
            i++;
        }
        
    }
    return 0;
}
/*******************************************************************/
/* eof */