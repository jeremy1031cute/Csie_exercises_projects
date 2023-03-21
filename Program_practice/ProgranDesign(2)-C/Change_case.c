#include<stdio.h>
#define MAX 10001
int main(){
    char str[MAX];
    int choice = 0;
    int len;

    gets(str);
    len = strlen(str);
    scanf(" %d", &choice);

    //printf("123");
    switch(choice)
    {
        case 1:

             for(int i = 0; i < len; i++){
                if(str[i] >= 'a' && str[i] <= 'z')
                    str[i] = str[i] - 'a' + 'A';
                printf("%c", str[i]);
            }
            break;
        case 2:
            for(int i = 0; i < len; i++){
                if(str[i] >= 'A' && str[i] <= 'Z')
                    str[i] = str[i] + 'a' - 'A';
                printf("%c", str[i]);
            }
            break;
        case 3:
            for(int i = 0; i < len; i++){
                if(i % 2 == 0){
                    if(str[i] >= 'a' && str[i] <= 'z')
                        str[i] = str[i] - 'a' + 'A';
                    printf("%c", str[i]);
                }
                else{
                    if(str[i] >= 'A' && str[i] <= 'Z')
                        str[i] = str[i] + 'a' - 'A';
                    printf("%c", str[i]);
                }
            }
            break;
        default:
            break;
    }


    return 0;
}
