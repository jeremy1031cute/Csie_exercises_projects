#include <stdio.h>

int func(int n) {
    if (n == 0) {
        return 1;
    } else {
        return func(n - 1) + func(n / 2);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", func(n));
}
