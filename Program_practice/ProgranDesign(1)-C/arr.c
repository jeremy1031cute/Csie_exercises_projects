#include<stdio.h>
int interger_array[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int interger_array_2[10]={0};

int index_insert, insert_value;
void insertion (int i, int i_value);

int index_update, update_value;
void updation (int u, int v_value);

void traverse(void);

int index_delete;
void deletion (int d);


int main(){
    int num_action=0;
    char action_arr[50];

    printf("num of actions:\n");
    scanf(" %d", &num_action);

    for(int i=0;i<num_action;i++){
        scanf(" %c", &action_arr[i]);
    }

    for(int i=0;i<num_action;i++){
        switch(action_arr[i]){
            case 'i':
                printf("position to insert:\n");
                scanf(" %d", &index_insert);
                if(0 <=index_insert && index_insert<10){
                    printf("enter the value to insert:\n");
                    scanf(" %d", &insert_value);
                    insertion(index_insert, insert_value);
                }
                else{
                    printf("INVALID POSITION\n");
                }
                break;
            case 'u':
                printf("position to update:\n");
                scanf(" %d", &index_update);
                if(0 <=index_update && index_update<10){
                    printf("enter the value to update:\n");
                    scanf(" %d", &update_value);
                    updation(index_update, update_value);
                }
                else{
                    printf("INVALID POSITION\n");
                }
                break;
            case 't':
                traverse();
                break;
            case 'd':
                printf("position to delete:\n");
                scanf(" %d", &index_delete);
                if(0 <=index_delete && index_delete<10){
                    deletion(index_delete);
                }
                else{
                    printf("INVALID POSITION\n");
                }
                break;
            default:
                printf("INVALID ACTION\n");
                break;
        }
    }

    return 0;
}

void insertion (int i, int i_value){
    for (int j=0;j<10;j++){
        if (j < index_insert)
          interger_array_2[j] = interger_array[j];
        else if( j == index_insert)
          interger_array_2[j] = insert_value;
        else
          interger_array_2[j] = interger_array[j-1];
    }
    for (int j=0;j<10;j++){
        interger_array[j]=interger_array_2[j];
    }
    traverse();
}

void updation (int u, int u_value){
    interger_array[u] = u_value;
    traverse();
}

void traverse(){
    for (int i=0;i<10;i++){
        printf("%d ",interger_array[i]);
    }
    printf("\n");
}

void deletion (int d){
    interger_array[d] = 0;
    traverse();
}
