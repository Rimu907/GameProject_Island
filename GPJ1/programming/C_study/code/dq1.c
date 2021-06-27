#include <stdio.h>
#include<math.h>
float location(float vx,float vy,float t)
{
	int i;
	float x,y,time;
	for(i=1;i<=10;i++)
	{
		x=t*i/10*vx;
		y=vy*t*i/10-4.905*t*i/10*t*i/10;
        time=t*i/10;
		printf("t%d=%.3fs  ",i,time);
		printf("x%d=%.3fm  ",i,x);
		printf("y%d=%.3fm\n",i,y);
	}
}
float VXY(float a,float v,float *pvx,float *pvy)
{
  *pvx=v*cos(a*3.14159265359/180);
  *pvy=v*sin(a*3.14159265359/180);
   printf("vx=%.3fm/s\n",*pvx);
   printf("vy=%.3fm/s\n",*pvy);
}
float T(float vy )
{
	printf("TOF=%.3fs\n",2*vy/9.81);
    return(2*vy/9.81);
}
int main()
{
	float v,vx,vy,t;
	float a;
	float *pvx,*pvy;
	pvx=&vx;
	pvy=&vy;
	printf("Enter the Angle (a) and  the velocity (v):");
	scanf("%f%f",&a,&v);
	if (a>=0&&v>=0)
	{
	   VXY(a,v,pvx,pvy);
	   t=T(vy);
    }
	else if(a<0||v<0)
    {
      printf("\nthe data of the Angle or the velocity is wrong \n--------------------\n");
    }
    location(vx,vy,t);
    getch();
	return (0);
}
