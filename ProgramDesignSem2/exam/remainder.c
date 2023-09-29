#include <stdio.h>
#include <string.h>

void go_remainder(char *a, int b) {
    int len = strlen(a);
    long long int remainder = 0;

    for (int i = 0; i < len; i++) {
        int digit = a[i] - '0';
        remainder = (remainder*10 + digit) % b;
    }

    printf("%lld", remainder);
}

int main() {
    int m;
    char a[101];
    int b;

    scanf("%d", &m);
    scanf("%s", a);
    scanf("%d", &b);

    go_remainder(a, b);

    return 0;
}
