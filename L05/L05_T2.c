/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L05_T2
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 1.10.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>
#include <stdlib.h>

int tarkistaSyote(char *);
int* varaaMuisti(int);
void taytaTaulukko(int *, int);
void tulostaTaulukko(int *, int);
void vapautaMuisti(int *);

int main(int argc, char *argv[]) {
    int koko;
    int *taulu;

    if (argc < 2) {
        perror("Et antanuttaulukon kokoa.");
        exit(0);
    }

    if (!(koko = tarkistaSyote(argv[1])))
    {
        perror( "Parametri ei ollut positiivinen kokonaisluku.");
        exit(0);
    }

    taulu = varaaMuisti(koko);
    if (taulu == NULL)
    {
        perror("Muistin varaus epäonnistui");
        exit(0);
    }
    
    taytaTaulukko(taulu, koko);
    tulostaTaulukko(taulu, koko);
    return 0;
}

int tarkistaSyote(char *syote){
    int luku = atoi(syote);

    if (syote == NULL || luku < 1)
        return 0;
    
    return luku;
}

int* varaaMuisti(int koko){
    return (int*)malloc(koko * sizeof(int));
}

void taytaTaulukko(int *taulu, int koko){
    printf("Taulukossa on tilaa %d alkiolle.\n", koko);
    for (int i = 0; i < koko; i++)
    {
        printf("Anna %d. luku: ", i+1);
        scanf("%d", &taulu[i]);
    }
}

void tulostaTaulukko(int *taulu, int koko){
    printf("Taulukossa on luvut: ");
    for (int i = 0; i < koko; i++)
    {
        printf("%d ", taulu[i]);
    }
    printf("\n");
}

void vapautaMuisti(int *taulu){
    free(taulu);
    taulu = NULL;
}
/*******************************************************************/
/* eof */