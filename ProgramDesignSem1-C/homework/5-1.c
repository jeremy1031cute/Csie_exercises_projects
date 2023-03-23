#include<stdio.h>
int GCD(int w1,int w2);

int main(){
    int G[100]={0}, N[100];
    int i, j, k=0;
    while(k != 99){
            scanf(" %d", &N[k]);
            if(N[k] == 0)
                break;
            k++;
    }

    k=0;
    while(k != 99){
        for(i=1;i<N[k];i++){
            for(j=i+1;j<=N[k];j++){
                G[k]+=GCD(i,j);
            }
        }
            if(N[k] == 0)
                break;
            printf("%d\n",G[k]);
            k++;
    }
    return 0;
}

int GCD(int w1,int w2){
    int common_factor;

    if(w2>w1)
        common_factor=w1;
    else
        common_factor=w2;

    while(1 < common_factor && w2 != 0 && w1 != 0){
        if(w2%common_factor!=0 || w1%common_factor!=0)
            common_factor--;
        else
            break;
    }
    if(w2 == 0 && w1 == 0)
        common_factor=0;
    else if(w2 == 0 && w1 != 0)
        common_factor=w1;
    else if(w2 != 0 && w1 == 0)
        common_factor=w2;

    return common_factor;
}
