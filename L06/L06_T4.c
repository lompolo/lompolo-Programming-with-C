/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L06_T4
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
    printf("1) Luo lista\n");
    printf("2) Lisää alkio listan loppuun\n");
    printf("3) Lisää alkio listan keskelle\n");
    printf("4) Tyhjennä lista\n");
    printf("5) Poista alkio listasta\n");
    printf("6) Tulosta lista\n");
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

Alkio *tyhjennaLista(Alkio *alku){
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
        printf("\n");
    else {
         while (p != NULL)
        {
            printf("%d ", p->luku);
            p = p->seuraava;
        }
        printf("\n");
    }
}

int listanPituus(){
    int pituus;

    printf("Anna listan pituus: ");
    scanf("%d", &pituus);

    if (pituus < 0)
    {
        printf("Listan pituus ei voi olla negatiivinen.\n");
        pituus = -1;
    }
    
    return pituus;
}

Alkio *luoLista(Alkio *alku, int pituus, int ensimmainen){
    if (alku != NULL)
    {
        alku = tyhjennaLista(alku);
    }

    for (int i = ensimmainen; i < (ensimmainen + pituus); i++)
    {
        alku = lisaaLoppuun(alku, i);
    }

    return alku;
}

Alkio *lisaaListaan(Alkio *alku){
    return alku;
}

Alkio *poistaListalta(Alkio *alku){
    return alku;
}

int main() {
    Alkio *alku = NULL;
    int jatka = TRUE;
    int valinta = 0, pituus = 0, uudenListanAloitus = 1;

    printf("Tämä ohjelma hallitsee listaa ja sen alkioita.\n");

    while (jatka)
    {
        valinta = paavalikko();
        switch (valinta)
        {
        case 0:
            jatka = FALSE;
            alku = tyhjennaLista(alku);
            printf("Kiitos ohjelman käytöstä.\n");
            break;

        case 1:
            pituus = listanPituus();

            if (pituus == -1)
                break;

            alku = luoLista(alku, pituus, uudenListanAloitus);
            tulostaLista(alku);
            uudenListanAloitus += pituus;
            break;

        case 2:
            alku = lisaaLoppuun(alku, uudenListanAloitus);
            tulostaLista(alku);
            uudenListanAloitus++;
            break;

        case 3:
            alku = lisaaListaan(alku);
            break;

        case 4:
            alku = tyhjennaLista(alku);
            break;

        case 5:
            alku = poistaListalta(alku);
            break;

        case 6:
            tulostaLista(alku);
            break;

        default:
            printf("Tuntematon valinta, yritä uudestaan.\n");
        }
    }
    
    return 0;
}
/*******************************************************************/
/* eof */