#include "stdio.h"
void main()
{
    int a,b,c;
    printf("���������ߵ�ֵa,b,c:\n");
    printf("ע��cΪб��\n");
    scanf("%d,%d,%d",&a,&b,&c);
    if (c>a+b||c<a-b)
    {
        printf("����������\n");
    }
    else if(c*c<a*a+b*b&&c*c!=a*a+b*b)
    {
        printf("���������\n");
    }
    else if(c*c==a*a+b*b)
    {
        printf("ֱ��������\n");
    }
    else if (c*c>a*a+b*b)
    {
        printf("�۽�������\n");
    }
    getch();
    return ;
}
