#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define NAME_LENGTH 49

/*Input form:
<number of courses>
<course_id> <next> <piror> <course name>
*/
int main(){
    int course_num;
    scanf("%d", &course_num);

    struct course{
        int course_id;
        struct course *next;
        struct course *prior;
        int next_num;
        int prior_num;
        char name[NAME_LENGTH];
    };

    struct course *first = NULL, *current = NULL;
    struct course *arr[course_num];

    //initialization
    for(int i = 0; i < course_num; i++){
        arr[i] = (struct course *)malloc(sizeof(struct course));
        scanf(" %d %d %d %s", &arr[i]->course_id, &arr[i]->next_num, &arr[i]->prior_num, arr[i]->name);
        if(i == 0){
            first = arr[i];
            current = first;
        }
        arr[i]->next = NULL;
        arr[i]->prior = NULL;
    }

    //link next pointer of struct course
    //WRONG: for(; current != NULL; current = current->next){ //not working at ex3, some next_num is negative
    for(int i = 0; i < course_num; i++){
        current = arr[i];
        for(int j = 0; j < course_num; j++){
            if((arr[j])->course_id == current->next_num){
                current->next = arr[j];
                break;
            }
        }
    }

    //link prior pointer of struct course
    //WRONG: for(current = first; current != NULL; current = current->prior){ //can,t use if prior_num is negative number
    for(int i = 0; i < course_num; i++){ //the first pointer,s prior_num may be negative number
        current = arr[i];
        for(int j = 0; j < course_num; j++){
            if((arr[j])->course_id == current->prior_num){
                current->prior = arr[j];
                break;
            }
        }
    }

    current = first;
    printf("Current Course: %s\n", current->name);
    while(1){
        char check;
        printf("[n] Next course. [p] Prior course [q] Quit: ");
        scanf(" %c", &check);
        if(check == 'n' && current->next == NULL){
            printf("There is no next course.\n");
            printf("Current Course: %s\n", current->name);
        }else if(check == 'p' && current->prior == NULL){
            printf("There is no previous course.\n");
            printf("Current Course: %s\n", current->name);
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

    for(int i = 0; i < course_num; i++){//not regular linklist, better use index to free space(easy & convinient)
        free(arr[i]);
    }

    return 0;
}
