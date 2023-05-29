#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
    srand( time(NULL) );
    int record[10] = {0,0};
    int i , j;
    int max = 20;//int max = max_id();
    for (i = 1; i <= 10; i++) {
        if (max <10) {
            printf("The number of questions is not enough!(< 10)\n");
            return NULL;
        }
        do {
            record[i - 1] = rand() % (max - 1 + 1) + 1;
            for (j = 1; j < i; j++) {
                if(record[i - 1] == record[j - 1]){
                    break;
                }
            }
        } while (j != i);
        printf("%d ", record[i - 1]);
    }
    printf("\n");

    return 0;
}
