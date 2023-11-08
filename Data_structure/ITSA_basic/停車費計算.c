#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int hour1, min1;
    int hour2, min2;
    int time;

    scanf("%d %d", &hour1, &min1);
    scanf("%d %d", &hour2, &min2);

    time = (hour2 * 60 + min2) - (hour1 * 60 + min1);

    if (time <= 60 * 2) {
        printf("%d\n", time / 30 * 30);
    } else if (time <= 60 * 4) {
        printf("%d\n", 120 + (time - 120) / 30 * 40);
    } else {
        printf("%d\n", 120 + 160 + (time - 240) / 30 * 60);
    }

    return 0;
}
