/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L02_T5
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 17.9.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define STR_LEN 200

int main() {
	char str[STR_LEN] = "";
	int len = 0;
	int cont = TRUE;
	int nValinta;
	char c;

	while (cont) {
		printf("\nValikko\n");
		printf("1) Lisää uusi merkki\n");
		printf("2) Tyhjennä merkkijono\n");
		printf("3) Tulosta merkkijono\n");
		printf("0) Lopeta\n");
		printf("Valintasi: ");
		scanf("%d", &nValinta);
		printf("\n");

		switch (nValinta)
		{
		case 0:
			cont = FALSE;
			printf("Ohjelman lopetus.\n");
			break;
		case 1:
			if (len < STR_LEN){
				printf("Anna jokin merkki: ");
				scanf("%s", &c);
				str[len] = c;
				len++;
			} else {
				printf("Merkkijonoon ei mahdu enempää merkkejä.\n");
			}
			break;
		case 2:
			if (len > 0) {
				for (int i = 0; i < len; i++)
				{
					str[i] = ' ';
				}
				len = 0;
				printf("Merkkijono on tyhjennetty.\n");
			}
			break;
		case 3:
			if (len != 0) {
				printf("Merkkijono: ");
				for (int i = 0; i < len; i++)
				{
					printf("%c", str[i]);
				}
				printf("\n");
			} else {
				printf("Merkkijono on tyhjä.\n");
			}
			break;
		default:
			printf("Tuntematon valinta.\n");
			break;
		}
	}

    return 0;
}
/*******************************************************************/
/* eof */