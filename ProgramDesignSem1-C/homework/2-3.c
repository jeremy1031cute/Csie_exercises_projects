#include <stdio.h>
int main(void)
{
    int x;

    scanf("%d",&x);

    if (x<0 || 100<x)
    printf("error");
    else{

    if (90<=x&&x<=100)
    x=1;
    else if (75<=x&&x<=89)
    x=2;
    else if (60<=x&&x<=74)
    x=3;
    else
    x=4;

    switch(x) {

	  case 1:  printf("A");
               break;
	  case 2:  printf("B");
	           break;
	  case 3:  printf("C");
	           break;
	  default: printf("D");
	           break;
              }

        }


    return 0;
}
