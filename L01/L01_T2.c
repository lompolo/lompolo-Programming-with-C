#include <stdio.h>

int main() {
    int iNumber;
    float fNumber;

    printf("Anna kokonaislukuluku: ");
    scanf("%d", &iNumber);
    printf("Anna liukuluku: ");
    scanf("%f", &fNumber);
    printf("Annoit luvut %d ja %.2f.\n", iNumber, fNumber);
    return 0;
}