#include "stdio.h"
void main ()
{
    int x,y;
    printf("the value of x is :\n");
    scanf("%d",&x);
    if(x<0)
        {y=-1;
        printf("y=%d\n",y);
        }
    else
    {
        if(x==0)
    {
        y=0;
        printf("y=%d\n",y);
    }

    else
    {   y=1;
        printf("y=%d\n",y);
    }
    }
    getch();
    return;

}
