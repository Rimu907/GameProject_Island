#include <stdio.h>
#include <math.h>
int sum(float x,float y)
{
    return (x+y);
}
int sub(float x,float y)
{
    return (x-y);
}
int div(float x,float y)
{
    return (x/y);
}
int tim(float x,float y)
{   if(y==0)
    {
    printf("gg");
    return;
    }
    return (x*y);
}
void main()
{
    float a,b,c=0;
    char sign;
    scanf("%f",&a);
    scanf("%c",&sign);
    scanf("%c",&sign);
    scanf("%f",&b);
    while(1)
{
    switch(sign)
   {
    case '+':c=sum(a,b);break;
    case '-':c=sub(a,b);break;
    case '/':c=div(a,b);break;
    case '*':c=tim(a,b);break;
    default: ;
   }
   printf("=%f",c);
   sign=getch();
   printf("%c",sign);
   scanf("%f",&b);
   a=c;
   if (sign=='q') break;
}
    printf("%f",c);
    return;
}
