#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int ten;
    int two[8];
    scanf("%d", &ten);

    if (ten < 0)
        ten += 256;

    for (int i = 7; i >= 0; i--) {
        two[i] = ten % 2;
        ten /= 2;
    }
    for (int i = 0; i <= 7; i++) {
        printf("%d", two[i]);
    }
    printf("\n");

    return 0;
}
