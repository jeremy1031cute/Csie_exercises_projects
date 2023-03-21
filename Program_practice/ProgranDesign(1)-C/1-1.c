#include <stdio.h>
int main()
{
    int month,day,year;
    char ch;

    scanf("%d%c%d%c%d",&month,&ch,&day,&ch,&year);
    printf("%04d%02d%02d",year,month,day);

    return 0;
}
