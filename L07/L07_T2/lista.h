/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L07_T2: lista.h
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 10.10.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
typedef struct Alkiot{
    int luku;
    struct Alkiot *seuraava;
} Alkio;

Alkio *lisaaLoppuun(Alkio *alku, int luku);
Alkio *tyhjennaLista(Alkio *alku);
void tulostaLista(Alkio *alku);
Alkio *luoLista(Alkio *alku, int pituus, int ensimmainen);
Alkio *haeSolmu(Alkio *alku, int paikka);
Alkio *lisaaListaan(Alkio *alku, int paikka, int luku);
Alkio *poistaListalta(Alkio *alku, int paikka);
Alkio *luoSolmu(Alkio *alku, int luku);

/*******************************************************************/
/* eof */
/*******************************************************************/