#include <stdio.h>
#include <stdlib.h>
#define NAME_LENGTH 49

int main(){
    int course_num;
    scanf("%d ", &course_num);

    struct course{
        char name[NAME_LENGTH];
        struct course *next;
        struct course *prior;
    }arr[course_num];



    for(int i = 0; i < course_num; i++){
        scanf("%d %d %d %s ", &course_id, &next, &piror, &course_name);
    }

    return 0;
}
