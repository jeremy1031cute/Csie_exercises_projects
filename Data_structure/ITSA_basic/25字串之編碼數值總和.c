#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n); //eat '\n'
    char str[33];
    int j;
    while((j = getchar()) != EOF && j!='\n'); //eat '\n' => Clear buffer

    for (int i = 0; i < n; i++) {
        int sum = 0;
        memset(str, -1, 33);
        gets(str);
        int len = strlen(str);
        if (str[len - 1] == '\n') {
            str[len - 1] = '\0';
            len--;
        }

        for (int j = 0; str[j] != '\0'; j++) {
            if (str[j] >= 32 && str[j] <= 126)
                sum += (int)(str[j]);
        }
        printf("%d\n", sum);
    }

}
