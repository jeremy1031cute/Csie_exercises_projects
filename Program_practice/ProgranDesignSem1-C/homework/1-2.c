#include <stdio.h>
int main()
{
    int month,day,year,ItemNumber;
    float UnitPrice;
    char ch;

    scanf("%d %f %d%c%d%c%d",&ItemNumber,&UnitPrice,&month,&ch,&day,&ch,&year);

    printf("Item    Unit    Purchase\n");
    printf("    \tPrice \tDate\n");
    printf("%d \t$%.2f \t%02d\\%02d\\%04d",ItemNumber,UnitPrice,month,day,year);

    return 0;
}
