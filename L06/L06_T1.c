/*******************************************************************/
/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L06_T1
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 5.10.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct Solmu {
    int luku;
    struct Solmu *seuraava;
}; 

typedef struct Solmu Lista; 

int main() {
    Lista *alku = NULL, *loppu = NULL, *p = NULL;
    int luku = 1;

    printf("Anna listan luvut.\n");
    while (luku != 0)
    {
        printf("Anna positiivinen kokonaisluku, 0 lopettaa: ");
        scanf("%d", &luku);
        if (luku != 0) {
            if((p = (Lista*)malloc(sizeof(Lista))) == NULL){
                perror("Muistin varaus epäonnistui.");
                exit(1);
            }

            p->luku = luku;
            p->seuraava = NULL;
            if (alku == NULL) {
                alku = p;
                loppu = p;
            } else {
                loppu->seuraava = p;
                loppu = p;
            }
        }
    }

    printf("Listassa on seuraavat luvut: ");
    p = alku;
    while (p != NULL)
    {
        printf("%d ", p->luku);
        alku = p->seuraava;
        free(p);
        p = alku;
    }
    printf("\n");

    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}
/*******************************************************************/
/* eof */