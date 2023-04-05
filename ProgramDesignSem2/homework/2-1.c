#include <stdio.h>
#include <stdlib.h>
#define NAME_LENGTH 49

int main(){
    int course_num;
    scanf("%d ", &course_num);

    struct course{
        int course_id;
        struct course *next;
        struct course *prior;
        int next_num;
        int prior_num;
        char name[NAME_LENGTH];
    };

    struct course *first = NULL, *current = NULL;

    for(int i = 0; i < course_num; i++){
        struct course *new_node;
        new_node = malloc(sizeof(struct course));
        scanf("%d %d %d %s ", &new_node->course_id, &new_node->next_num, &new_node->prior_num, new_node->name);
        if(i == 0){
            first = new_node;
            current = first;
            continue;
        }
        if(current->next_num == new_node->course_id){
            current->next = new_node;
        }else{
            current->next = NULL;
        }
        if(new_node->prior_num == current->course_id){
            current->prior = current;
        }else{
            current->next = NULL;
        }
        current = new_node;
    }

    current = first;
    printf("Current Course: %s\n", current->name);
    while(1){
        char check;
        printf("[n] Next course. [p] Prior course [q] Quit:");
        scanf(" %c", &check);
        if(check == 'n' && current->next == NULL){
            printf("There is no next course.\n");
        }else if(check == 'p' && current->prior == NULL){
            printf("There is no previous course.\n");
        }else if(check == 'q'){
            break;
        }else if(check == 'n'){
            current = current->next;
            printf("Current Course: %s\n", current->name);
        }else if(check == 'p'){
            current = current->prior;
            printf("Current Course: %s\n", current->name);
        }
    }

    return 0;
}
