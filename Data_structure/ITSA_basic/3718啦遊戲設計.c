#include <stdio.h>

int main(){

    int d0, d1, d2, d3;
    scanf("%d%d%d%d", &d0, &d1, &d2, &d3);
    if (d0 == d1 && d1 == d2 && d2 == d3)
        printf("WIN\n");
    else if (d0 != d1 && d0 != d2 && d0 != d3 && d1 != d2 && d1 != d3 && d2 != d3) //meaningless, all four different & any three same
        printf("R\n");
    else if (d0 != d1 && d1 == d2 && d2 == d3)
        printf("R\n");
    else if (d1 != d2 && d2 == d3 && d3 == d0)
        printf("R\n");
    else if (d1 != d2 && d1 == d3 && d3 == d0)
        printf("R\n");
    else if (d1 != d3 && d0 == d1 && d1 == d2)
        printf("R\n");
    else if (d0 == d1) {
        if (d2 != d3)
            printf("%d\n", d2 + d3);
        else
            printf("%d\n", (d0 + d1) > (d2 + d3) ? (d0 + d1) : (d2 + d3));
    }
    else if (d1 == d2) {
        if (d0 != d3)
            printf("%d\n", d0 + d3);
        else
            printf("%d\n", (d1 + d2) > (d0 + d3) ? (d1 + d2) : (d0 + d3));
    }
    else if (d2 == d3) {
        if (d0 != d1)
            printf("%d\n", d0 + d1);
        else
            printf("%d\n", (d0 + d1) > (d2 + d3) ? (d0 + d1) : (d2 + d3));
    }
    else if (d3 == d0) {
        if (d1 != d2)
            printf("%d\n", d1 + d2);
        else
            printf("%d\n", (d1 + d2) > (d0 + d3) ? (d1 + d2) : (d0 + d3));
    }
    else if (d1 == d3) {
        if(d0 != d2)
            printf("%d\n", d0 + d2);
        else
            printf("%d\n", (d1 + d3) > (d0 + d2) ? (d1 + d3) : (d0 + d2));
    }
    else if (d0 == d2) {
        if(d1 != d3)
            printf("%d\n", d1 + d3);
        else
            printf("%d\n", (d1 + d3) > (d0 + d2) ? (d1 + d3) : (d0 + d2));
    }

    return 0;
}
