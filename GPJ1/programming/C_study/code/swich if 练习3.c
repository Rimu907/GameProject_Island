#include "stdio.h"
void main()
{
    int x;
    printf("what is ur integer x:\n");
    scanf("%d",&x);
    if (x%3==0&&x%5==0&&x%7==0)
    {
        printf("����ͬʱ��3,5,7����\n");
    }
    else if (x%3==0&&x%5==0)
    {
        printf("����ͬʱ��3,5����\n");
    }
    else if (x%5==0&&x%7==0)
    {
        printf("����ͬʱ��5,7����\n");
    }
    else if (x%3==0&&x%7==0)
    {
        printf("����ͬʱ��3,7����\n");
    }
    else if (x%3==0)
    {
        printf("���Ա�3����\n");
    }
     else if (x%5==0)
    {
        printf("���Ա�5����\n");
    }
     else if (x%7==0)
    {
        printf("���Ա�7����\n");
    }
     else if (x%3!=0&&x%5!=0&&x%7!=0)
    {
        printf("���ܱ�3,5,7����\n");
    }
    getch();
    return ;
}
