/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L05_T3
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 2.10.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 30

enum boolean {FALSE, TRUE};

typedef struct Henkilo
{
    char nimi[MAX];
    int ika;
} Henkilo;

Henkilo* varaaHloMuisti(){
    return (Henkilo*)malloc(sizeof(Henkilo));
}

void vapautaMuisti(Henkilo *henkilo){
    free(henkilo);
    henkilo = NULL;
}

void kopioHenkilo(Henkilo *dest, const Henkilo *src){
    strcpy(dest->nimi, src->nimi);
    dest-> ika = src->ika;
}

int vertaileHenkilot(Henkilo *hlo1, Henkilo *hlo2){
    return (strcmp(hlo1->nimi, hlo2->nimi) || hlo1->ika != hlo2->ika) ? FALSE : TRUE;
}

int main() {
    Henkilo hlo1;
    Henkilo hlo2;
    Henkilo *hlo3;

    printf("Anna ensimmäisen henkilön etunimi: ");
    scanf("%s", hlo1.nimi);
    printf("Anna ensimmäisen henkilön ikä: ");
    scanf("%d", &hlo1.ika);
    printf("Anna toisen henkilön etunimi: ");
    scanf("%s", hlo2.nimi);
    printf("Anna toisen henkilön ikä: ");
    scanf("%d", &hlo2.ika);

    vertaileHenkilot(&hlo1, &hlo2) ? printf("Annetut tiedot ovat samoja.\n") : printf("Annetut tiedot eivät ole samoja.\n");

    hlo3 = varaaHloMuisti();
    if (hlo3 == NULL)
    {
        perror("Muistin varaus epäonnistui");
        exit(0);
    }
    kopioHenkilo(hlo3, &hlo1);

    vertaileHenkilot(&hlo1, hlo3) ? printf("Kopioinnin jälkeen tietueiden tiedot ovat samoja.\n") : printf("Kopioinnin jälkeen tietueiden tiedot eivät ole samoja.\n");
    &hlo1 == hlo3 ? printf("Kopioinnin jälkeen tietueiden osoitteet ovat samoja.\n") : printf("Kopioinnin jälkeen tietueiden osoitteet eivät ole samoja.\n");
    vapautaMuisti(hlo3);
    printf("Kiitos ohjelman käytöstä.\n");

    return 0;
}
/*******************************************************************/
/* eof */