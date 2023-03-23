#include <stdio.h>
#include <stdbool.h>
#define MAX_str 100001

int main(){
    char str[MAX_str];
    char word[100];
    int count = 0;
    int flag;//check if word is same with the str, if not, give the false to it and won't count

    fgets(str, MAX_str, stdin);
    scanf("%s", word);

    int str_len = strlen(str) - 1;
    str[str_len] = '\0';
    int word_len = strlen(word);
    //printf("str_len = %d, word_len = %d\n", str_len, word_len);

    for(int i = 0; i < str_len; i++){
        flag = true;
        for(int j = 0; j < word_len; j++){
            if(word[j] != str[i + j]){ //In order to prevent from user scanf only a letter
                flag = false;
                break;
            }
        }

        if(flag){
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
