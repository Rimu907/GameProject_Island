#include <stdio.h>
#include <math.h>
#define a -9.81
float Vx(float V0,float A)
{
    return (V0*cos( RadToAngle (A)));
}
float Vy(float V0,float A)
{
    return (V0*sin( RadToAngle (A)));
}
float t(float V0,float A)
{
    return (2*Vy/a);
}

void main()
{
    float V0,A,x,y;
    int i;
    printf("Enter the velocity V0:");
    scanf("%f",&V0);
    printf("Enter the Angle A:");
    scanf("%f",&A);

    if (V0<0||A<0) break;
    printf("The value of Vx is %f",Vx);
    printf("The value of Vy is %f",Vy);
    printf("The value of t is %3fs",t);

    for(i=1;i<=10;i++)
    {
        x=t*i/10*Vx;
        y=Vy*t*i/10-0.5*a*t*i/10*t*i/10;
        printf("x%d=%3f",i,x);
        printf("y%d=%3f",i,y);

    }

     return;



}
