#include <stdio.h>

int main() {
    int number1 = 0;
    int number2 = 0;

    printf("Anna ensimmäinen kokonaisluku: ");
    scanf("%d", &number1);
    printf("Anna toinen kokonaisluku: ");
    scanf("%d", &number2);

    printf("(%d + %d) * 2 = %d\n", number1, number2, ((number1 + number2) * 2));
    printf("(%d / %d) - 3 = %d\n", number1, number2, ((number1 / number2) - 3));

    int number3 = number1 + 1;
    int number4 = number2 - 1;
    printf("%d %% %d = %d\n", number3, number4, (number3 % number4));

    return 0;
}