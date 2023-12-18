int main() {
    int n, a1, a2, a3, m1, m5, m50;
    scanf("%d,%d,%d,%d", &n, &a1, &a2, &a3);

    if (n < a1*15+ a2*20+ a3*30) {
        printf("0\n");
        return 0;
    }
    n = n - (a1*15+ a2*20+ a3*30);
    m50 = n / 50;
    n = n % 50;
    m5 = n / 5;
    n = n % 5;
    m1 = n;

    printf("%d,%d,%d\n", m1, m5, m50);

}
