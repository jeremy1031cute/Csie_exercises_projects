int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main() {
    int n = 0;
    int t, m, k; //budget, gift number, goods number

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &t, &m, &k);
        int gifts[k];
        for (int j = 0; j < k; j++) {
            scanf("%d", &gifts[j]);
        }

        qsort(gifts, k, sizeof(int), cmpfunc);

        int sum = 0;

        for (int j = 0; j < m; j++) {
            sum += gifts[j];
        }

        if (sum > t)
            printf("Impossible\n");
        else
            printf("%d\n", sum);
    }
}
