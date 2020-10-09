/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L05_T4
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 2.10.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>
#include <stdlib.h>

enum Boolean {FALSE, TRUE};

int paavalikko() {
    int valinta;
    printf("1) Tulosta taulukon alkiot\n");
    printf("2) Muuta taulukon kokoa\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi: ");
    scanf("%d", &valinta);

    return valinta;
}

int* varaaMuisti(int koko){
    return (int*)malloc(koko * sizeof(int));
}

void vapautaMuisti(int *taulu){
    free(taulu);
    taulu = NULL;
}

void taytaTaulukko(int *taulu, int koko){
    for (int i = 0; i < koko; i++)
    {
        taulu[i] = i;
    }
}

void tulostaTaulukko(int *taulu, int koko){
    if (taulu == NULL || koko < 1)
        printf("Taulukko on tyhjä.\n");
    else {
        printf("Taulukon alkiot ovat: ");
        for (int i = 0; i < koko; i++)
        {
            printf("%d ", taulu[i]);
        }
        printf("\n");
    }
}

int taulukonKoko(){
    int koko;

    printf("Anna taulukon uusi koko: ");
    scanf("%d", &koko);

    if (koko < 0)
    {
        printf("Taulukon koko ei voi olla negatiivinen.\n");
        koko = -1;
    }
    
    return koko;
}

int main() {
    int jatka = TRUE;
    int valinta = 0;
    int *taulu = NULL;
    int koko = 0;
    int tmp = 0;

    while (jatka)
    {
        valinta = paavalikko();
        switch (valinta)
        {
        case 0:
            jatka = FALSE;
            vapautaMuisti(taulu);
            printf("Kiitos ohjelman käytöstä.\n");
            break;

        case 1:
            tulostaTaulukko(taulu, koko);
            break;

        case 2:
            tmp = taulukonKoko();

            if (tmp == -1)
                break;
            
            koko = tmp;

            if (taulu != NULL)
                vapautaMuisti(taulu);

            taulu = varaaMuisti(koko);
            if (taulu == NULL)
            {
                perror("Muistin varaus epäonnistui");
                exit(0);
            }

            taytaTaulukko(taulu, koko);
            break;

        default:
            printf("Tuntematon valinta, yritä uudestaan.\n");
        }
    }
    
    return 0;
}
/*******************************************************************/
/* eof */