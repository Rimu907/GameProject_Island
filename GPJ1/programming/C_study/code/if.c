#include "stdio.h"
void main()
{
   int a,b;
   printf("输入整数a：");
   scanf ("%d",&a);
   printf("输入整数b：");
   scanf ("%d",&b);
    if(a==b)
     printf("a=b\n");
    else
     printf("a!=b");
   getch();
   return;
}
