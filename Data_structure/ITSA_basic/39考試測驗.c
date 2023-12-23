#include <stdio.h>
int main() {
    int n;
    int s1, s2, s3;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &s1, &s2, &s3);

        int not_passed = 0;
        int sum = s1 + s2 + s3;
        if (s1 < 60) not_passed++;
        if (s2 < 60) not_passed++;
        if (s3 < 60) not_passed++;

        if (not_passed == 0)
            printf("P\n");
        else if (not_passed == 1 && sum >= 220)
            printf("P\n");
        else if (not_passed == 1 && sum <= 220)
            printf("M\n");
        else if (not_passed == 2 && (s1 >= 80 || s2 >= 80 || s3 >= 80))
            printf("M\n");
        else
            printf("F\n");
    }
}
