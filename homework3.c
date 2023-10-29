#include <stdio.h>

int main() {
    int current = 54;

    while (current <= 102) {
        printf("%d->", current);
        current += (current % 3 == 0) ? 6 : 3;
    }

    printf("\n");

    return 0;
}