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

#define MAX 20
const char FILENAME[10] = "luvut.bin";

void writeNumbers();
void readNumbers();

int main() {
    writeNumbers();
    readNumbers();
    return 0;
}

void writeNumbers(){
    FILE* tiedosto;
    srand(1);
    int arvo;

    if((tiedosto = fopen(FILENAME, "wb")) == NULL){
        perror("Lukujen kirjoittaminen epäonnistui");
    }

    for (size_t i = 0; i < MAX; i++)
    {
        arvo = rand()%1000;
        fwrite(&arvo, sizeof(arvo), 1, tiedosto);
    }
    printf("Lukujen tallennus onnistui.\n");
    fclose(tiedosto);
}

void readNumbers(){
    FILE* tiedosto;
    int arvo;

    if((tiedosto = fopen(FILENAME, "rb")) == NULL){
        perror("Lukujen lukeminen epäonnistui");
    }

    printf("Tiedostossa on seuraavat luvut:\n");
    for (size_t i = 0; i < MAX; i++)
    {
        fread(&arvo, sizeof(arvo), 1, tiedosto);
        printf("%d ", arvo);
    }
    printf("\n");
}
/*******************************************************************/
/* eof */