#include <stdio.h>
int main(void)
{
    int xx,yy;
    char ch;

    scanf("%d %c %d",&xx,&ch,&yy);

    if (xx<0 || yy<0 || 59<yy)
    printf("Incorrect Input");
    else if(xx<12 && xx>0)
    printf("%d:%02d AM",xx,yy);
    else if(xx==12)
    printf("12:%02d PM",yy);
    else if(xx>12 && xx<24)
    printf("%d:%02d PM",xx-12,yy);
    else if(xx==0 || xx==24)
    printf("12:%02d AM",yy);
    else
    printf("Incorrect Input");

    return 0;
}
