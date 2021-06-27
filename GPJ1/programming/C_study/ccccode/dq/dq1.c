#include <stdio.h>
#include<math.h>
int main()
{
    float location(float vx,float vy,float t,FILE *fp);
	float VXY(float a,float v,float *pvx,float *pvy,FILE *fp);
	float T(float vy ,FILE *fp);
	FILE *fp;
	int n;
	char m[30];
    printf("If the users want to named the text file ,press 1 then type in this form 'name.txt'\nFor example 'H61CAE.txt' \nOr just press 2:");
    scanf("%d",&n);
	if (n==1)
	{
     scanf("%s",m);
     fp=fopen(m,"w");
	}
	else
    {
     fp=fopen("D:\\dq1.txt","w");
    }
	float v,vx,vy,t;
	float a;
	float *pvx,*pvy;
	pvx=&vx;
	pvy=&vy;
	printf("Enter the Angle (a) and  the velocity (v):");
	scanf("%f%f",&a,&v);
	if (a>0&&a<180&&v>0)
	{
	   VXY(a,v,pvx,pvy,fp);
	   t=T(vy,fp);
    }
	else if(a<=0||a>=180||v<=0)
    {
      printf("\nthe data of the Angle or the velocity is wrong  \n--------------------\n");
      printf("the angle data should be 0<a<180,the velocity data should be v>0\n");
      return(0);
    }
    location(vx,vy,t,fp);
    fclose(fp);
    getch();
	return(0);
}
float location(float vx,float vy,float t,FILE *fp)
{
	int i;
	float x,y,time;
	for(i=1;i<=10;i++)
	{
		x=t*i/10*vx;
		y=vy*t*i/10-4.905*t*i/10*t*i/10;
        time=t*i/10;
		printf("t%d=%.3fs  ",i,time);
		fprintf(fp,"t%d=%.3fs  ",i,time);
		printf("x%d=%.3fm  ",i,x);
		fprintf(fp,"x%d=%.3fm  ",i,x);
		printf("y%d=%.3fm\n",i,y);
		fprintf(fp,"y%d=%.3fm\n",i,y);
	}
}
float VXY(float a,float v,float *pvx,float *pvy,FILE *fp)
{
  *pvx=v*cos(a*3.14159265359/180);
  *pvy=v*sin(a*3.14159265359/180);
   printf("vx=%.3fm/s\n",*pvx);
   fprintf(fp,"vx=%.3fm/s\n",*pvx);
   printf("vy=%.3fm/s\n",*pvy);
   fprintf(fp,"vy=%.3fm/s\n",*pvy);
}
float T(float vy ,FILE *fp)
{
	printf("TOF=%.3fs\n",2*vy/9.81);
	fprintf(fp,"TOF=%.3fs\n",2*vy/9.81);
    return(2*vy/9.81);
}

