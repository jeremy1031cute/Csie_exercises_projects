#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_word 100
#define MAX_str 100000

int main(){
    char *str[MAX_str];
    char word[MAX_word];
    int count = 0, word_num = 0;
    int flag = 1;//check if word is same with the str, if not, give the false value to it and won't count
    char check;//check if character is '\n'

    do{
        str[word_num] = (char*)malloc(sizeof(char)*MAX_word);
        scanf("%s", str[word_num++]);
    }while((check = getchar()) != '\n');

    fgets(word, MAX_word, stdin);
    int word_len = strlen(word) - 1;
    word[word_len] = '\0';


    //printf("str_len = %d, word_len = %d\n", str_len, word_len);

    for(int i = 0; i < word_num; i++){
        for(int j = 0; j < word_len; j++){
            if(word_len == strlen(str[i])){
                flag = 1;
                if(word[j] != *(*(str+i)+j)){
                    flag = 0;
                    break;
                }
            }
            else{
                flag = 0;
                break;
            }
        }
        if(flag == 1)
            count++;
    }
    //printf("%d\n", word_num);
    printf("%d", count);

    return 0;
}
