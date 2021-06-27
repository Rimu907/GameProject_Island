#include <stdio.h>

void main()
{
    int a,b,t;
    int *pointer_1,*pointer_2;
    scanf("%d,%d",&a,&b);
    pointer_1=&a;
    pointer_2=&b;
    if(a<b)
    {
      t= *pointer_1;
      *pointer_1 = *pointer_2;
      *pointer_2 = t;

    }

     printf("%d,%d",*pointer_1,*pointer_2);
    return;
}
