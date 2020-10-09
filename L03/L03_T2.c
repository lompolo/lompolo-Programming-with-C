/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L03_T2
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 17.9.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 50
#define TRUE 1
#define FALSE 0
const char FILENAME[10] = "nimet.txt";

void kirjoitaNimi(char *s);
void tulostaNimet();

int main() {
    int jatka = TRUE;
    char nimi[MAX_LEN] = "";
    int nValinta = 0;

    printf("Ohjelma tallentaa nimiä tiedostoon.\n\n");

    while (jatka)
    {
        printf("1) Tallenna uusi nimi\n");
        printf("2) Tulosta nimet\n");
        printf("0) Lopeta\n");
        printf("Valitse: ");
        scanf("%d", &nValinta);
        printf("\n");

        if (nValinta == 1)
        {
            printf("Anna tallennettava nimi: ");
            scanf("%s", nimi);
            kirjoitaNimi(nimi);
        } else if (nValinta == 2)
        {
            printf("Tiedostossa olevat nimet:\n");
            tulostaNimet();
        } else if (nValinta == 0)
        {
            jatka = FALSE;
        } else {
            printf("Tuntematon valinta.\n");
        }    
    }
    return 0;
}

void kirjoitaNimi(char *s) {
    FILE *tiedosto = fopen(FILENAME, "a");

    if(tiedosto == NULL){
        perror("Error");
        exit(1);
    }

    fprintf(tiedosto, "%s\n", s);
    printf("Nimi on tallennettu tiedostoon.\n\n");
    fclose(tiedosto);
}

void tulostaNimet() {
    FILE *tiedosto = fopen(FILENAME, "r");
    char rivi[MAX_LEN] = "";

    if(tiedosto == NULL){
        perror("Error");
        exit(1);
    }

    
    while (fgets(rivi, MAX_LEN, tiedosto) != NULL)
    {
        printf("%s", rivi);
    }
    printf("\n");
    
    fclose(tiedosto);
}
/*******************************************************************/
/* eof */