#include "stdio.h"
void main()
{
    int x;
    printf("what is ur integer x:\n");
    scanf("%d",&x);
    if (x%3==0&&x%5==0&&x%7==0)
    {
        printf("可以同时被3,5,7整除\n");
    }
    else if (x%3==0&&x%5==0)
    {
        printf("可以同时被3,5整除\n");
    }
    else if (x%5==0&&x%7==0)
    {
        printf("可以同时被5,7整除\n");
    }
    else if (x%3==0&&x%7==0)
    {
        printf("可以同时被3,7整除\n");
    }
    else if (x%3==0)
    {
        printf("可以被3整除\n");
    }
     else if (x%5==0)
    {
        printf("可以被5整除\n");
    }
     else if (x%7==0)
    {
        printf("可以被7整除\n");
    }
     else if (x%3!=0&&x%5!=0&&x%7!=0)
    {
        printf("不能被3,5,7整除\n");
    }
    getch();
    return ;
}
