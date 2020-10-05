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

typedef enum {FALSE, TRUE} Boolean;

typedef struct Solmu {
    int luku;
    struct Solmu *seuraava;
} Lista;

int main() {
    Lista *alku, *loppu, *p;
    int luku;
    Boolean jatka = TRUE;

    printf("Anna listan luvut.\n");
    while (jatka)
    {
        printf("Anna positiivinen kokonaisluku, 0 lopettaa: ");
        scanf("%d", &luku);
        if (luku == 0)
            jatka = FALSE;
        else {
            if((p = (Lista*)malloc(sizeof(Lista))) == NULL){
                perror("Muistin varaus epäonnistui.");
                exit(0);
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