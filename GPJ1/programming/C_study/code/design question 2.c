#include <stdio.h>
#include<math.h>
float location(float vx,float vy,float t)
{
    float v;
    float a;
    printf("请输入发射角a和初速度v:");
    scanf("%f%f",&a,&v);
    vx=v*cos(a*3.14159265359/180);
    printf("vx=%f",vx);
    vy=v*sin(a*3.14159265359/180);
    printf("vy=%f",vy);
    t=2*vy/9.8;
    printf("%.3f s",t);


}
void main()
{
    int i;
    float v,vx,vy,t;
    float x,y;

    for(i=1;i<=10;i++)
    {
		x=t*i/10*vx;
		y=vy*t*i/10-4.9*t*i/10*t*i/10;
		printf("x%d=%.3f    ",i,x);
		printf("y%d=%.3f\n",i,y);
	}
	location(vx,vy,t);
	return;
}
