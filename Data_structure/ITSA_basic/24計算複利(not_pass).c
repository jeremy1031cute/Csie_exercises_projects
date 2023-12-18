int main() {
    double r;
    long long int n ,p;
    double money = 0;
    scanf("%lf %lld %lld", &r, &n, &p);

    for (int i = 0; i < n; i++) {
        money += (double)p;
        money *= (1.0 + r);
    }
    printf("%.lf\n", money);
}
