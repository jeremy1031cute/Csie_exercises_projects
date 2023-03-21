#include <stdio.h>
int main()
{
    int a,b,c,d,e;
    char ch;

    scanf("%d%c%d%c%d%c%d%c%d",&a,&ch,&b,&ch,&c,&ch,&d,&ch,&e);

    printf("%03d\n%03d\n%03d\n%03d\n%03d",a,b,c,d,e);

    return 0;
}
