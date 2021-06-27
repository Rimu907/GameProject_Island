#include <stdio.h>
#include <stdlib.h>

void main()
{
    int i ,sum;
    i=1;
    sum=0;
   do
   {sum=sum+i;
    i=i+1;
   }while(i<101);
   printf("%d",sum);
   return;
}
