#include <stdio.h>
int main()
{
    int x=0;
    scanf("%d",&x);
    int a = x/100,b = x/50,c = x/10,d = x/5;


    if(1000 >= x && x >=1)
    {printf("%dg bags: %d\n%dg bags: %d\n%dg bags: %d\n%dg bags: %d\n%dg bags: %d"
    ,100,a,50,(x-a*100)/50,10,(x-b*50)/10,5,(x-c*10)/5,1,x-d*5);}
    else
    {printf("error!\n");}

    return 0;
}
