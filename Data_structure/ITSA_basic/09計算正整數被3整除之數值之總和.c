#include <stdio.h>

int main()
{
    int sum = 0, n = 0;

    scanf("%d", &n);
    for(int i = 1; i <= n; i++) { //notice <=
        if (i % 3 == 0) {
            sum += i;
        }
    }
    printf("%d\n", sum);
}
