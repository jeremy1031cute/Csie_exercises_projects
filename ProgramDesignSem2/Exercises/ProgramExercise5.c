#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
size_t my_strlen(const char* str); //Returns the length of the C string str.
int clean_new_line_character(char* str, int l);
char* my_strcpy(char* dest, const char* source); //Copy string from source to dest.
char* my_strcat(char* dest, const char* source); //Concatenate strings from source to dest.
//int my_strcmp(const char* str1, const char* str2); //Compares str1 to str2. The rules of comparison are the same as the strcmp().

int main(){
    char *str, *str_new, *str_longest;
    str_longest = (char *) calloc(sizeof(char) * 101);
    *str_longest = '\0';
    int sentence_count = 0;
    int len, longest_len = 0;
    /*char* combine;
    combine = (char *) calloc(sizeof(char) * 8192);*/

    //do{
        str = (char *) malloc(sizeof(char) * 101);
        fgets(str, 101, stdin);
        sentence_count++;
        len = my_strlen(str);
        len = clean_new_line_character(str, len);
        if(len >= longest_len){
            longest_len = len;
            free(str_longest);
            my_strcpy(str_longest, str);
        }else if(len == longest_len){
            //my_strcmp();
        }
        //my_strcat(combine, str)
        free(str);
    //}while(getchar() != EOF)


    printf("number of sentence: %d\n", sentence_count);
    printf("longest sentence: %s\n", str_longest);
    printf("longest length: %d\n", longest_len);
    //printf("%s", combine);
    return 0;
}

size_t my_strlen(const char* str){
    size_t sum = 0;
    while(*(str + sum)){ //ASCII of '\0' is 0 (Implicit Conversions)
        sum++;
    }
    return sum;
}

int clean_new_line_character(char* str, int l){
    if(*(str + l - 1) == '\n'){
        *(str + l - 1) = '\0';
        l--;
    }
    return l;
}

char* my_strcpy(char* dest, const char* source){
    int index = 0;
    while(*(source + index) != '\0'){
        *(dest + index) = *(source + index);
        index++;
    }
    *(dest + index) = '\0';
    return dest;
 }

char* my_strcat(char* dest, const char* source){
    int i, j;
    for (i = 0; *(dest + i) != '\0'; i++);
    for (j = 0; *(source + j) != '\0'; j++) {
        *(dest + i + j) = *(source + j);
    }
    *(dest + i + j) = '\0';
    return dest;
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
