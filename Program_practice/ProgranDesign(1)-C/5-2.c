#include<stdio.h>
int main(){
    int n;//使用者字型指定行數
    scanf("%d",&n);
    int N;
    int flag = 0;

    int i=2;
    int Fibonaccimal[100];
    Fibonaccimal[0]=1;
    Fibonaccimal[1]=2;
    while(Fibonaccimal[i-1]<100000000){
        Fibonaccimal[i]=Fibonaccimal[i-1]+Fibonaccimal[i-2];
        i++;
    }


    for(int j=0;j<n;j++){
        scanf("%d",&N);
        printf("%d = ", N);
        for(int k=i-1;k>=0;k--){
            if((N/Fibonaccimal[k])>0){
                printf("1");
                flag = 1;
                N -= Fibonaccimal[k];
            }
            else if(flag == 1 && (N/Fibonaccimal[k])<=0)
                printf("0");
        }
        printf(" (fib)\n");
        flag = 0;
    }
    return 0;
}
