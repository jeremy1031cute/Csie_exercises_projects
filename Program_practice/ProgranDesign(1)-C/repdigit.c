#include<stdio.h>
int main(){
    char ch=0;
    int record[10]={0};
    int flag=0;//���p��e�����s

    while(ch != EOF){
        ch=getchar();
        if('0' <= ch && ch <= '9')
            if(ch!='0')
                flag=1;
            if(flag==1)
                record[(int)ch-48]++;
    }

    printf(" 0 1 2 3 4 5 6 7 8 9\n");

    for(int i=0;i<10;i++){
        printf(" %d",record[i]);
    }
    return 0;
}
