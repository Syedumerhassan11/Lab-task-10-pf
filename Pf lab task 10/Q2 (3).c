#include <stdio.h>
void calculatePercentage(int value, int percent) {
    if (percent > 100) {
        return;
    }
    printf("%d Percent = %.2f\n", percent, (value * percent) / 100.0);
    calculatePercentage(value, percent + 1); 
}

int main() {
    int value;
    printf("Enter a value to split in percentage: ");
    scanf("%d", &value);

    calculatePercentage(value, 1);
    return 0;
}

