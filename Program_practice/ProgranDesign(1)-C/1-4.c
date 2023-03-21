#include <stdio.h>
int main()
{
    int a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16;

    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
    &a1,&a2,&a3,&a4,&a5,&a6,&a7,&a8,&a9,&a10,&a11,&a12,&a13,&a14,&a15,&a16);

    printf("%d \t%d \t%d \t%d\n",a1,a2,a3,a4);
    printf("%d \t%d \t%d \t%d\n",a5,a6,a7,a8);
    printf("%d \t%d \t%d \t%d\n",a9,a10,a11,a12);
    printf("%d \t%d \t%d \t%d\n",a13,a14,a15,a16);
    printf("%d \t%d \t%d \t%d\n",a1+a2+a3+a4,a5+a6+a7+a8,a9+a10+a11+a12,a13+a14+a15+a16);
    printf("%d \t%d \t%d \t%d\n",a1+a5+a9+a13,a2+a6+a10+a14,a3+a7+a11+a15,a4+a8+a12+a16);
    printf("%d \t%d",a1+a6+a11+a16,a4+a7+a10+a13);

    return 0;
}
