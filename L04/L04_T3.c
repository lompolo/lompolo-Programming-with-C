/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L04_T3
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 30.9.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {

   if (argc < 2)
   {
      printf("Et antanut syötteitä.\n");
   } else if(argc == 4){
      if ((atof(argv[1]) == 0.0 && *argv[1] == '0') || (atof(argv[3]) == 0.0 && *argv[3] == '0'))
      {
         printf("Virheellinen syöte.\n");
      } else {
         if (strlen(argv[2]) > 1){
            printf("Virheellinen syöte.\n");
         } else {
            switch (argv[2][0])
            {
            case '+':
               printf("%s + %s = %.2f\n", argv[1], argv[3], atof(argv[1]) + atof(argv[3]));
               break;

            case '-':
               printf("%s - %s = %.2f\n", argv[1], argv[3],  atof(argv[1]) - atof(argv[3]));
               break;

            case 'x':
               printf("%s x %s = %.2f\n", argv[1], argv[3],  atof(argv[1]) * atof(argv[3]));
               break;

            case '/':
               printf("%s / %s = %.2f\n", argv[1], argv[3],  atof(argv[1]) / atof(argv[3]));
               break;
            default:
               printf("Virheellinen syöte.\n");
            }
         }
      }
   } else {
      printf("Virheellinen syöte.\n");
   }

  return 0;
}    
/*******************************************************************/
/* eof */