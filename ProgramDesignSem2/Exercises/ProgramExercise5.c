#include <stdio.h>
#include <stdlib.h>
size_t my_strlen(const char* str); //Returns the length of the C string str.
//char* my_strcpy(char* dest, const char* source); //Copy string from source to dest.
//char* my_strcat(char* dest, const char* source); //Concatenate strings from source to dest.
//int my_strcmp(const char* str1, const char* str2); //Compares str1 to str2. The rules of comparison are the same as the strcmp().

int main(){
    char *str;
    str = (char *) malloc(sizeof(char) * 100);
    fgets(str, 100, stdin);

    printf("%d", my_strlen(str));
    free(str);
    /*while(1){
        fgets(str, 100, stdin);

    }*/
    //printf("");
    return 0;
}

size_t my_strlen(const char* str){
    size_t sum = 0;
    while(*(str + sum)){
        sum++;
    }
    /*if(*(str + sum) == '\n'){
        *(str + sum) = '\0';
        sum--;
    }*/
    return sum;
}

//Knowledge learn fron min-huang teaching assistant
/*
    1.When you use Windos system like txt. file, it will have two new line character '\n' and '\r',the two character will be printed together,
        there is no difference betweem the two except the name.
        p.s. linux only have '\n' character. most of the time, teaching assistant will use it .
        it might be better to use
        if(*(str + sum) == '\n' || *(str + sum) == '\r'){
            *(str + sum) = '\0';
            sum--;
        }
    2.When you use git,sometimes will happen CONFILCT when you edit the file and other also do it at the same time
        the newest one will cover the one hand in early,
        btw git usually have some built-in function to solve it automatically.
        It is better to check the history and edit it in person, arrange the schedule wisely, or write different file(each responsible for diff function)

    3.you can use pointer to edit varible declared by const, but the behavior will generate warning to ask u just not to use const.
*/
