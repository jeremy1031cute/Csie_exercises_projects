#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d ", &n);

    for (int i = 0 ; i < n; i++) {
        char num1[31] = {0}, num2[31] = {0};
        int sorted1[31] = {0}, sorted2[31] = {0};
        scanf("%s %s", num1, num2);
        int len1 = strlen(num1), len2 = strlen(num2);

        for (int i = 0; i < len1; i++) {
            sorted1[30 - i] = num1[len1 - i - 1] - '0';
        }
        for (int i = 0; i < len2; i++) {
            sorted2[30 - i] = num2[len2 - i - 1] - '0';
        }

        for (int j = 30 ; j > 0; j--) {
            sorted1[j] += sorted2[j];
            sorted1[j - 1] += sorted1[j] / 10;
            sorted1[j] = sorted1[j] % 10;
        }

        int start = 0;
        while (sorted1[start] == 0 && start < 30) {
            start++;
        }

        for (int i = start; i <= 30; i++) {
            printf("%d", sorted1[i]);
        }
        printf("\n");
    }
}
