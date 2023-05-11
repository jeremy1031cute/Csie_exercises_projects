#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"
#define MAX_LINE_LEN 60

//char line[MAX_LINE_LEN+1]; *line array will be replaced by a variable that points to the node containing the first word.
struct linklist{
    char word[MAX_LINE_LEN];
    struct linklist *next;
};
struct linklist *first = NULL;
int line_len = 0;
int num_words = 0;

void clear_line(void){ //claers the current line
    struct linklist *ptr;//temporary to store clearing line
    //delete all node
    while(first != NULL){
        ptr = first;
        first = first->next;
        free(ptr);
    }
    line_len = 0;
    num_words = 0;
}

void add_word(const char *word){ //adds word to the end of cur line.If this is not the first word on the line, puts one space before word
    struct linklist *new_node = malloc(sizeof(struct linklist));
    strcpy(new_node->word, word);
    new_node->next = NULL;
    if(first == NULL){
        first = new_node;
    }
    else{
        struct linklist *ptr = first;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    line_len += strlen(word);
    if (num_words > 0) {
        line_len++;
    }
    //strcat(line, word);
    num_words++;
}

int space_remaining(void){ //return num of char left in the cur line
    return MAX_LINE_LEN - line_len;
}

void write_line(void){ //write the cur line with justification
    int extra_spaces, spaces_to_insert, j;
    extra_spaces = MAX_LINE_LEN - line_len;
    for(struct linklist *ptr = first; ptr != NULL; ptr = ptr->next){
        printf("%s", ptr->word);
        if(ptr->next != NULL){
            spaces_to_insert = extra_spaces / (num_words - 1);
            for(j = 1; j <= spaces_to_insert + 1; j++){
                putchar(' ');
            }
            extra_spaces -= spaces_to_insert;
            num_words--;
        }
    }
    putchar('\n');
}

void flush_line(void){ //write the cur line WITHOUT justification.if the line is empty, does nothing.
    for(struct linklist *ptr = first; ptr != NULL; ptr = ptr->next){
        printf("%s", ptr->word);
        if(ptr->next != NULL && ptr->word[(int)strlen(ptr->word) - 1] != ' '){//notice whitespace
            putchar(' ');
        }
    }
    putchar('\n');
}
