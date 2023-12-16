#include <stdio.h>
int gcd(int a, int b) {
    if (a < b) {
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
    if (a % b == 0)
        return b;
    else
        return gcd(a % b, b);

}

int main()
{
    int a, b;

    scanf("%d %d", &a, &b);
    printf("%d\n", gcd(a, b));
}
