#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define  case_sensitive 1
#define  case_insensitive 2

int main(){
    int num;
    int option;

    scanf("%d ", &option);
    scanf("%d ", &num);
    //fflush(stdin);

    char *str[num];

    int mini_len = 100;
    int mini_index = 0;
    for(int i = 0; i < num; i++){
        str[i] = (char *) malloc(sizeof(char) * 100);//�@�}�l���V�õL�Ŷ��A�n�����t�Ŷ��A���H�b��p�󬢨�n�B�a���t(����100����m)�A�N���ר����ΤG���}�C�ӿ�J�r���²��
        fgets(str[i], 100, stdin);
        if(str[i][strlen(str[i]) - 1] == '\n'){
            str[i][strlen(str[i]) - 1] = '\0';
            //printf("yes\n");
        }

        if(i != 0){
            if(strlen(str[i]) < mini_len){
                mini_len = strlen(str[i]);
                mini_index = i;
            }
        }
    }
    //printf("mini_len:%d\n", mini_len);
    switch(option){
        case case_sensitive:
            break;
        case case_insensitive:
            for(int i = 0; i < num; i++){
                for(int j = 0; j < mini_len; j++){ //better run less times
                    str[i][j] = tolower(str[i][j]);
                }
            }
            break;
        default:
            break;
    }

    for(int i = 0; i < num; i++){
        for(int j = 0; j < mini_len; j++){
            if(str[mini_index][j] != str[i][j]){
                str[mini_index][j] = '\0';
            }
        }
    }

    if(strlen(str[mini_index]) == 0){
        printf("No longest common prefix");
    }
    else{
        printf("%s", str[mini_index]);
    }

    return 0;
}
