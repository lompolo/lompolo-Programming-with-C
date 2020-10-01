/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L04_T5
 * Tekijä: Tero Lompolo
 * Opiskelijanumero: 0615760
 * Päivämäärä: 30.9.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>

#define MAX 2
#define MAXSTRING 20

typedef struct Matrix
{
    int matrix[MAX][MAX];
} Matrix;


void tulostaMatariisi(Matrix matrix, char nimi[MAXSTRING]){
    printf("\n");
    printf("%s:\n", nimi);

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%4d",matrix.matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

Matrix kysyMatriisi() {
    Matrix matrix;

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("Rivi %d alkio %d: ", i+1, j+1);
            scanf("%d", &matrix.matrix[i][j]);
        }
    }

    return matrix;
} 

Matrix laskeMatriisi(Matrix m1, Matrix m2){
    Matrix summaM;

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            summaM.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
        }
    }

    return summaM;

}

int main() {
    Matrix matrix1;
    Matrix matrix2;
    Matrix summaMatrix;
    printf("Anna arvot yhteenlaskettaville matriiseille:\n");

    printf("Matriisin 1 alkiot:\n");
    matrix1 = kysyMatriisi();
    tulostaMatariisi(matrix1, "Matriisi 1");
    
    printf("Matriisin 2 alkiot:\n");
    matrix2 = kysyMatriisi();
    tulostaMatariisi(matrix2, "Matriisi 2");

    summaMatrix = laskeMatriisi(matrix1, matrix2);
    tulostaMatariisi(summaMatrix, "Summamatriisi");
}
/*******************************************************************/
/* eof */