#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node{
        char *word;
        struct node *next;
    };

int main(){
    int word_num = 0;
    char *first = NULL, *current = NULL;
    do{
        struct node *new_node;
        new_node = (char *)calloc(1024, sizeof(char));
        current =
        if((word_num++) == 0)
            first = new_node;
    }while(fgets(current, 1024, stdin) != NULL);

    for(int i = 0; i < word_num; i++){
        //if(word[0] == '-'){}
        //if(word)
    }

    //for(int i = 0; i < word_num; i++) printf("%s: %d\n", word, word_num);

    return 0;
}
