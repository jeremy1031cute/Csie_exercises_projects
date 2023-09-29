// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
int main(){

    char ff[20];
    fgets(ff, 20, stdin);
    int len = strlen(ff);
    printf("len:%d\n", len);
    for(int i = 0; i<20; i++){
        if(ff[i] == '\0')//the last one is defenitely,must be '\0'
            printf("0");
        else if(ff[i] == '\n')
            printf("n");
        else
            printf("x");
    }
    printf("\nlen:%d\n", len);
    printf("%s", ff);
    //you type 18 char and u will get 19 len(18+'\n')
    //you type 19 char and u will get 19 len(19+'\0')
    //we could know fgets() won't add '\n' when user scanf more than(include) n-1 char
        return 0;
}

//the last one must be null
a b c '\n' '\0'
int len = strlen(line);
if (line[len - 1] == '\n'){
    line[len - 1] = '\0';
    len--;
}
