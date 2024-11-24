#include <stdio.h>

int sumOfDigits(int n) {
    if (n < 10)
        return n;
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    if (number < 0) {
        number = -number;
    }

    printf("The sum of digits of %d is %d\n", number, sumOfDigits(number));
    return 0;
}

