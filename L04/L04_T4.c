/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L04_T4
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 28.9.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX 50

typedef struct Kayttaja
{
    int id;
    char kTunnus[MAX];
    char salasana[MAX];
} Kayttaja;

Kayttaja tunnukset[MAX];

int paavalikko() {
    int valinta;
    printf("Valitse alla olevasta valikosta haluamasi toiminto:\n");
    printf("1) Lisää uusi tunnus\n");
    printf("2) Tulosta tunnukset\n");
    printf("0) Lopeta\n");
    printf("Valintasi: ");
    scanf("%d", &valinta);
    printf("\n");

    return valinta;
}

void lisaaKayttaja(int *viimeinenID){
    Kayttaja kayttaja;
    char kTunnus[MAX];
    char salasana[MAX];

    printf("Anna käyttäjätunnus: ");
    scanf("%s", kTunnus);
    printf("Anna salasana: ");
    scanf("%s", salasana);
    printf("Tunnus '%s' lisättiin listaan.\n", kTunnus);
    printf("\n");

    kayttaja.id = *viimeinenID;
    strcpy(kayttaja.kTunnus, kTunnus);
    strcpy(kayttaja.salasana, salasana);

    tunnukset[*viimeinenID] = kayttaja;
    *viimeinenID += 1;

    return;
}

void tulostaKayttajat(int *viimeinenID){
    printf("Listalla olevat tunnukset:\n");

    for (int i = 0; i < *viimeinenID; i++)
    {
        printf("%d. tunnus '%s', salasana '%s', ID '%d'.\n", i+1, tunnukset[i].kTunnus, tunnukset[i].salasana, tunnukset[i].id);
    }
    
    printf("\n");
}

int main() {
    int viimeinenID = 0;
    int jatka = TRUE;
    int valinta;

    printf("Käyttäjätunnusten hallinta.\n");
    while (jatka)
    {
        valinta = paavalikko();

        switch (valinta)
        {
        case 0:
            jatka = FALSE;
            break;

        case 1:
            lisaaKayttaja(&viimeinenID);
            break;

        case 2:
            tulostaKayttajat(&viimeinenID);
            break;
        }
    }
    
}
/*******************************************************************/
/* eof */