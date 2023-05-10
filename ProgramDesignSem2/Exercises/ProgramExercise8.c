#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_LENGTH 100

typedef struct D_linklist{ /* determine the structure by yourself. e.g, container of data, index... */
    int num;
    struct D_linklist *next;
} darray;

void initialize(darray *d);
void push_back(darray *d, int value);
int pop_back(darray *d);
int erase(darray *d, int position);
void insert(darray *d, int position, int value);
void clear(darray *d);
int sum(darray *d);
int length(darray *d);

void initialize(darray *d) {
    d->next = NULL;//d means the pointer to first node, and it doesn't have space
}

void push_back(darray* d, int value) {
    //initialize
    struct D_linklist *new_node = malloc(sizeof(darray));
    new_node->num = value;
    new_node->next = NULL;
    //go to the final node
    struct D_linklist *ptr = d;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    //push
    ptr->next = new_node;
}

int pop_back(darray* d) {
    struct D_linklist *ptr = d;
    while(ptr->next->next != NULL){ //you have to make the node which in front of final node 's next member point to NULL, we don't have prior member
        ptr = ptr->next;
    }
    //ptr->next->next means the final node's next member
    int removed_value = ptr->next->num;
    free(ptr->next);
    ptr->next = NULL;
    return removed_value;
}

int erase(darray *d, int position) {// return 0, if fail erase the element.
    struct D_linklist *ptr = d;     //return 1, if successfully erase the element.
    if(position == 0){
        if(ptr->next == NULL)
            return 0;
        ptr = ptr->next->next;
        free(d->next);
        d->next = ptr;
    }else{
        for(int i = 0; i < position; i++){ //d don't have index  d->next:index:0
            ptr = ptr->next;                //position:n ptr_index:n-1
            if(ptr->next == NULL)
                return 0;
        }

        struct D_linklist *temp = ptr->next->next;
        free(ptr->next);
        ptr->next = temp;
    }
    return 1;
}
//BE CAREFUL
void insert(darray *d, int position, int value) {
    //initialize
    struct D_linklist *new_node = malloc(sizeof(darray));
    new_node->num = value;
    new_node->next = NULL;

    struct D_linklist *ptr = d;
    if(position == 0){
        ptr = ptr->next;
        d->next = new_node;
        new_node->next = ptr;
    }else{
        for(int i = 0; i < position; i++){//position:n ptr_index:n-1
            ptr = ptr->next;
        }
        struct D_linklist *ptr2 = ptr->next;
        ptr->next = new_node;
        new_node->next = ptr2;
    }
}

void clear(darray *d) {
    while(d->next != NULL){
        struct D_linklist *ptr2 = d->next->next;//record the second node
        free(d->next);//dele the first node
        d->next = ptr2;
    }
}

int sum(darray *d) {
    int summ = 0;
    struct D_linklist *ptr = d;
    while(ptr->next != NULL){
        ptr = ptr->next;
        summ += ptr->num;
    }
    /*printf("array: ");
    ptr = d;
    while(ptr->next != NULL){
        ptr = ptr->next;
        printf("%d ", ptr->num);
    }
    printf("\n");*/
    return summ;
}

int length(darray *d) {
    int len = 0;
    struct D_linklist *ptr = d;
    while(ptr->next != NULL){
        ptr = ptr->next;
        len++;
    }
    return len;
}

//YOU CAN'T MODIFY THE main() FUNCTION!!!
int main() {
    darray d;
    initialize(&d);
    int operation, param1, param2;
    while(scanf("%d", &operation)) {
        switch (operation)
        {
        case 1: //push_back
            scanf("%d", &param1);
            push_back(&d, param1);
            break;
        case 2: //pop_back
            printf("popped: %d\n", pop_back(&d));
            break;
        case 3: //erase
            scanf("%d", &param1);
            if(erase(&d, param1))
                printf("erase OK\n");
            else
                printf("erase not OK\n");
            break;
        case 4: //insert
            scanf(" %d %d ", &param1, &param2);
            insert(&d, param1, param2);
            break;
        case 5:
            clear(&d);
            break;
        case 6:
            printf("sum: %d\n", sum(&d));
            break;
        case 7:
            printf("length: %d\n", length(&d));
            break;
        case 0:
            return 0;
        default:
            break;
        }
    }
}
