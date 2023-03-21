#include<stdio.h>
int main(){
    int quiz[5][5];
    for(int j=0;j<5;j++){
        for(int i=0;i<5;i++){
            scanf("%d",&quiz[j][i]);
        }
        printf("\n");
    }

    for(int k=0;k<5;k++){
        printf("%d %d %d\n",k+1,quiz[k][0]+quiz[k][1]+quiz[k][2]+quiz[k][3]+quiz[k][4],(quiz[k][0]+quiz[k][1]+quiz[k][2]+quiz[k][3]+quiz[k][4])/5);
    }
    return 0;
}
