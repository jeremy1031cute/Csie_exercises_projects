#include <stdio.h>
#include <stdlib.h>

int main()
{
    char word[101];
    int count[26] = {0}, word_num = 0;

    gets(word);

    for (int i = 0; word[i] != '\0'; i++) { //turn small letter into big
        if (word[i] >= 97 && word[i] <= 122)
            word[i] = word[i] - 32;//97 - x = 65, x = 32
    }

    for (int i = 0; word[i] != '\0'; i++) {
        if(word[i] == ' ')
            word_num++;
        if(word[i] >= 65 && word[i] <= 90)
            count[word[i] - 65]++;
    }
    word_num++;

    printf("%d\n", word_num);
    for (int i = 0;i < 26; i++) {
        if(count[i])
            printf("%c : %d\n",i + 97,count[i]);
    }
}
