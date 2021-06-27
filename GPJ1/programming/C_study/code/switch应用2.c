#include "stdio.h"
void main()
{
    int a,b,c;
    printf("输入三个边的值a,b,c:\n");
    printf("注意c为斜边\n");
    scanf("%d,%d,%d",&a,&b,&c);
    if (c>a+b||c<a-b)
    {
        printf("不是三角形\n");
    }
    else if(c*c<a*a+b*b&&c*c!=a*a+b*b)
    {
        printf("锐角三角形\n");
    }
    else if(c*c==a*a+b*b)
    {
        printf("直角三角形\n");
    }
    else if (c*c>a*a+b*b)
    {
        printf("钝角三角形\n");
    }
    getch();
    return ;
}
