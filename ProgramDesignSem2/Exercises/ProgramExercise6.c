#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define ADDyo 123
#define MINUSyo 987
#define FIND 21
#define NOFIND 27


struct node{
    char word[1025];
    int word_num;
    struct node *next;
};

//check certain node's word and add, minus word_num
int search(struct node **start, char name[], int add_or_minus);//return value FIND or NOFIND
//create new node
void insert(struct node **start, char name[]);

int main(){
    struct node *first = NULL;
    char product[1025];
    int result;

    while(fgets(product, 1025, stdin) != NULL){
        int len = strlen(product);
        product[len - 1] = '\0';

        if(product[0] == '-'){
            for(int i = 0; i < len; i++){
                product[i] = product[i + 1];
            }
            result = search(&first, product, MINUSyo);
            if(result == FIND){
                continue;
            }else if(result == NOFIND){
                insert(&first, product);
            }
        }
        else{
            result = search(&first, product, ADDyo);
            if(result == FIND){
                continue;
            }else if(result == NOFIND){
                insert(&first, product);
            }
        }
    }

    for(struct node *ptr = first; ptr != NULL; ptr = ptr->next){
	     printf("%s: %d\n", ptr->word, ptr->word_num);
    }

    while(first != NULL){
        struct node *ptr2 = first;
        first = first->next;
        free(ptr2);
    }

    return 0;
}

//search()->check product whether have been add at linklist¡Aif it have, add or minus word_num
int search(struct node **start, char name[], int add_or_minus){
    struct node *current = (*start);
    //WRONG:dangling pointer --> while(strcmp(name, current->word) != 0 && current != NULL) =>can't use the pointer which point ro null to check the item
    while(current != NULL && strcmp(name, current->word) != 0){//pay attention at order of conditions
        current = current->next;
    }
    if(current == NULL){
        return NOFIND;
    }
    if(add_or_minus == ADDyo){
        current->word_num++;
    }else if(add_or_minus == MINUSyo){
        current->word_num--;
    }
    return FIND;
}

void insert(struct node **start, char name[]){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    strcpy(new_node->word, name);
    new_node->word_num = 1;
    new_node->next = NULL;

    if(*start == NULL){//if first
        *start = new_node;
        return;
    }

    //insert new node at the tail of the linklist
    struct node *current = (*start);
    while (current->next != NULL){
        current = current->next;
    }
    current->next = new_node;
}
