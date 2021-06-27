#include "stdio.h"
#include "math.h"
void main ()
{
    float a ,b, c ,p ,q ,X1 ,X2 ;

    printf("what is ur a,b,c\n");

    scanf("%f,%f,%f",&a,&b,&c);

    p=-b/(2*a);
    q=(sqrt(b*b-4*a*c))/(2*a);

    X1= p+q ;
    X2= p-q ;
    printf ("the X1 is %5.1f\nthe X2 is %5.1f",X1,X2);
    getch();
    return;
}
