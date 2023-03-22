#include <stdio.h>
int main()
{
    int a,b,c,d,e,f,g,h;
    char r,t,x,y,z;

    scanf("%d%c%d%c",&a,&r,&b,&z);
    scanf("%d%c%d%c",&c,&t,&d,&z);
    scanf("%d%c%d%c",&e,&x,&f,&z);
    scanf("%d%c%d%c",&g,&y,&h,&z);


    printf("%d\n%d\n%d\n%.2f",a+b,c-d,e*f,(float)g/h);

    return 0;
}
