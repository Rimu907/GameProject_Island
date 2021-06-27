#include "stdio.h"
#include "math.h"
void main()
{
   int i,t;
   t=1;
   i=2;
   do
   {t=t*i;
    i=i+1;
   }while(t<=5);
    printf("%d",t);
    return ;
}
