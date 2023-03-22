#include <stdio.h>
int main(void)
{
   int i,j,n,x,y;

   scanf("%d",&n);
   y=n;

   for(j=0;j<n;j++)
   {
      x=y-1;
      while(x!=0){
         printf(" ");
         x--;
      }
      y--;

      for(i=0;i<=j*2;i++)
         printf("*");

      printf("\n");
   }

   return 0;
}
