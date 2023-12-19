#include <stdio.h>
#define MAN 1
#define WOMAN 2

int main () {
    int s, h;
    while (scanf("%d", &h) != EOF) {
        scanf("%d", &s);
        if (s == MAN)
            printf("%.1f\n", (float) (h - 80) * 0.7);
        else if (s == WOMAN)
            printf("%.1f\n", (float) (h - 70) * 0.6);
    }
}
