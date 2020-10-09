/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L06_T3
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 7.10.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>
#include <stdlib.h>

enum Boolean {FALSE, TRUE};

typedef struct Alkiot{
    int luku;
    struct Alkiot *seuraava;
} Alkio;


int paavalikko() {
    int valinta;
    printf("1) Tulosta listan alkiot\n");
    printf("2) Muuta listan pituutta\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi: ");
    scanf("%d", &valinta);

    return valinta;
}

Alkio *lisaaLoppuun(Alkio *alku, int luku){
    Alkio *p = (Alkio*)malloc(sizeof(Alkio)), *tmp = alku;

    /* Create new node */

    if(p == NULL){
        fprintf(stderr, "Muistinvaraus epäonnistui.\n");
        exit(0);
    };

    p->luku = luku;
    p->seuraava = NULL;

    /*Find last node */

    if (tmp != NULL)
    {
        while (tmp->seuraava != NULL)
            tmp = tmp->seuraava;
    }

    if (alku == NULL)
        alku = p;
    else
        tmp->seuraava = p;

    return alku;
}

Alkio *vapautaMuisti(Alkio *alku){
    Alkio *p = alku;
    while (p != NULL)
    {
        alku = p->seuraava;
        free(p);
        p = alku;
    };

    alku = NULL;

    return alku;
}

void tulostaLista(Alkio *alku){
    Alkio *p = alku;

    if (p == NULL)
        printf("Lista on tyhjä.\n");
    else {
        printf("Listassa on seuraavat luvut: \n");
         while (p != NULL)
        {
            printf("%d ", p->luku);
            p = p->seuraava;
        }
        printf("\n");
    }
}

int taulukonKoko(){
    int koko;

    printf("Anna listan uusi pituus: ");
    scanf("%d", &koko);

    if (koko < 0)
    {
        printf("Listan pituus ei voi olla negatiivinen.\n");
        koko = -1;
    }
    
    return koko;
}

int main() {
    Alkio *alku = NULL;
    int jatka = TRUE;
    int valinta = 0, koko = 0;

    while (jatka)
    {
        valinta = paavalikko();
        switch (valinta)
        {
        case 0:
            jatka = FALSE;
            alku = vapautaMuisti(alku);
            printf("Kiitos ohjelman käytöstä.\n");
            break;

        case 1:
            tulostaLista(alku);
            break;

        case 2:
            koko = taulukonKoko();

            if (koko == -1)
                break;

            if (alku != NULL)
            {
                alku = vapautaMuisti(alku);
            }

            for (int i = 0; i < koko; i++)
            {
                alku = lisaaLoppuun(alku, i);
            }
            

            break;

        default:
            printf("Tuntematon valinta, yritä uudestaan.\n");
        }
    }
    
    return 0;
}
/*******************************************************************/
/* eof */