#include <stdio.h>

int main()
{
    char array[100000];
    scanf("%s", array);
    int len = strlen(array);
    int flag = 0;

    for (int i = 0; i < len; i++) {
        if (array[i] != array[len - i - 1]) {
            flag = 1;
            break;
        }
    }

    if(flag != 1)
        printf("YES\n");
    else
        printf("NO\n");
}
