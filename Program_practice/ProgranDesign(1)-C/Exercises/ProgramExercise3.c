#include <stdio.h>

int A (int i,int j);
int R (int i);

int main(void)
{
    int i,j,p;
    char G,g,r;

    scanf("%d %c%c%c %d",&i,&G,&g,&G,&j);
    printf("%d\n",A(i,j));
    scanf(" %c %d",&r,&p);
    R(p);

    return 0;
}

int A (int i,int j)
{
    int x=0;

    while(x<j)
    {
    if(i%j == 0)
      return i;
    else
        i++;
    x++;
    }
}

int R (int i)
{
    printf("%03d",(i%10)*100+(10*((i/10)%10))+(i/100));
}
