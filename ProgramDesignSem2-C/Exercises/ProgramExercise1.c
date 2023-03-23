#include<stdio.h>
#include <string.h>
#define MAX 101

int reverse(char *str);

int main(){

    char str1[MAX], temp_str1[MAX];
    char str2[MAX], temp_str2[MAX];
    int operation = 0;
    int count;
    int check[6]={0};
    int sum =0;
    //better use fgets();
    fgets(str1, MAX, stdin);//gets(); can receive the space and won,t stop
    fgets(str2, MAX, stdin);
    int len1 = strlen(str1), len2 = strlen(str2);
    str1[len1-1] = '\0';//fgets(); will add "\n"
    str2[len2-1] = '\0';/*fget();無null最後一位是\n*/
    //printf("len1 = %d , len2 = %d", len1, len2);

    while(1){
        scanf(" %d", &operation);
        switch(operation){
            case 1:
                strcpy(temp_str1, str1);
                strcpy(temp_str2, str2);
                reverse(temp_str1);
                reverse(temp_str2);
                printf("Reverse A: %s\n", temp_str1);
                printf("Reverse B: %s\n", temp_str2);
                break;
            case 2:
                printf("The length of A: %d\n", len1-1);
                printf("The length of B: %d\n", len2-1);
                break;
            case 3:
                strcpy(temp_str1, str1);
                strcpy(temp_str2, str2);
                strcat(temp_str1, temp_str2);
                printf("The string after concatenates: %s\n", temp_str1);
                break;
            case 4:
                if (strcmp(str1, str2) < 0){
                    printf("A is less than B.\n");
                }
                else if(strcmp(str1, str2) == 0){
                    printf("A is equal to B.\n");
                }
                else{
                    printf("A is greater than B.\n");
                }
                break;
            case 5:
                count = 0;
                //len1 = strlen(str1);  //don,t put strlen(str1); in the for(loop),it will calaulate many times, and don't work effectively
                for(int i = 0; i < len1; i++){
                    if(str1[i] == ' ')
                        count++;
                }
                printf("Whitespace of A: %d\n", count);
                break;
            case 6:
                count = 0;
                for(int i = 0; i < len2; i++){
                    if(str2[i] == ' ')
                        count++;
                }
                printf("Whitespace of B: %d\n", count);
                break;
            default:
                printf("Error!\n");
                break;
        }

        //check whether all num have been choose?
        if(operation >= 1 && operation <= 6){
            check[operation-1] = 1;
        }

        for(int i = 0; i < 6; i++){
            sum += check[i];
        }

        if(sum == 6)
            break;

        sum = 0;
    }

    return 0;
}

int reverse(char *str){
    int i, j;
    char temp;

    j=strlen(str) - 1;
    for(i=0; i<j; i++){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        j--;
    }
    return 0;
}
