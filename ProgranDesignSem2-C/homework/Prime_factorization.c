#include<stdio.h>
int main(){
    int num;
    int i = 2, j;

    scanf("%d", &num);

    while(i <= num){
        if(num % i == 0)
        {
            printf("%d ", i);
            num /= i;
        }
        else
        {
            i++;
        }
    }

    return 0;
}
