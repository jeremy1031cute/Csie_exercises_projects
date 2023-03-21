#include<stdio.h>
int main(){
    int i, j, k;
    scanf("%d %d",&i,&j);//�H�ĤG�j���Ʃ��U��

    if(i>j){
        k=j;
    }
    else{
        k=i;
    }

    while(1<k && i!=0 && j!=0){
        if(i%k!=0 || j%k!=0)
            k--;
        else{
            printf("%d",k);
            return 0;
        }
    }
        
    if(i==0 && j==0)
        printf("0");
    else if(i==0 && j!=0)
        printf("%d",j);
    else if(i!=0 && j==0)
        printf("%d",i);
    else
        printf("1");

    return 0;

}
