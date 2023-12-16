#include <stdio.h>

int main()
{
    int round = 0;
    int a1 = 0, b1 = 0; //b (-1)^(1/2)
    int a2 = 0, b2 = 0;
    char compute;
    scanf("%d", &round);

    for(int i = 0; i < round; i++) {
        scanf(" %c %d %d %d %d", &compute, &a1, &b1, &a2, &b2);
        switch (compute) {
            case '+':
                printf("%d %d\n", a1 + a2, b1 + b2);
                break;
            case '-':
                printf("%d %d\n", a1 - a2, b1 - b2);
                break;
            case '*':
                printf("%d %d\n", a1 * a2 - b1 * b2, a1 * b2 + a2 * b1);
                break;
            case '/':
                printf("%d %d\n", (a1 * b2 + a2 * b1)/(a2 * a2 + b2 * b2), (a1 * a2 - b1 * b2)/(a2 * a2 + b2 * b2));
                break;
            default:
                break;
        }
    }

    return 0;
}
