#include <stdio.h>

int main()
{
    int num = 0, i;

    scanf("%d", &num);
    for(i = 2; i < num - 1; i++) {
        if (num % i == 0) {
            break;
        }
    }
    //printf("i : %d\n", i);
    if (num % i != 0)
        printf("YES\n");
    else
        printf("NO\n");
}
