#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str1[129], str2[513];
    int word_num = 0, flag = 0;

    gets(str1);
    gets(str2);
    int len1 = strlen(str1), len2 = strlen(str2);


    for (int i = 0; i < len2-1; i++) {
        for (int j = 0; j < len1-1; j++) { //notice '\n'
            if (str2[i + j] != str1[j]) {
                flag = 1;
                break;
            }
        }
        if (flag != 1)
            word_num++;
        flag = 0;
    }
    printf("%d\n", word_num);
}
