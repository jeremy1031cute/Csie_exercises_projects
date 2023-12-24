#include <stdio.h>
int main() {
    int num[10];
    for(int i = 0; i < 10; i++){
        char input_c;
        if (i != 9)
            scanf("%c ", &input_c);
        else
            scanf("%c", &input_c);

        if (input_c == 'X')
            num[i] = 10;
        else
            num[i] = input_c - '0';
    }

    for (int i = 1; i < 10; i++) {
        num[i] += num[i-1];
    }
    for (int i = 1; i < 10; i++) {
        num[i] += num[i-1];
    }

    if (num[10 - 1] % 11 == 0)
        printf("YES\n");
    else
        printf("NO\n");
}
