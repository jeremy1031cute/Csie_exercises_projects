#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    //r = 100
    int x, y;
    scanf("%d %d", &x, &y);
    if (x*x + y*y <= 100*100) {
        printf("inside\n");
    } else {
        printf("outside\n");
    }

    return 0;
}
