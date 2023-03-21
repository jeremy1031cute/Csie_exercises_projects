#include<stdio.h>
void swap(int *ptr1, int *ptr2);
int main(){
    int n;
    scanf("%d", &n);
    int array[2][n];

    for(int j=0; j<2; j++){
        for(int i=0; i<n; i++){
            scanf("%d", &array[j][i]);
        }
    }

    for(int i=0; i<n; i++){
        swap(&array[0][i], &array[1][i]);
    }

    printf("1st array: ");
    for(int i=0; i<n; i++){
        printf("%d ", array[0][i]);
    }
    printf("\n");
    printf("2nd array: ");
    for(int i=0; i<n; i++){
        printf("%d ", array[1][i]);
    }
    return 0;
}

void swap(int *ptr1, int *ptr2){
    int tmp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=tmp;
}
