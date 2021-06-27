#include<stdio.h>
#define pi 3.14159265359
int main()
{
    float T(float vy,FILE *fp);
    float VXY(float a,float v,float *pvx ,float *pvy,FILE *fp);
    float location(float vx,float vy,float t,FILE *fp);

    FILE *fp;
    int n ;
    char m[50];
    printf("press 1 or 2.\n");
    scanf("%d",&n);
    if (n==1)
    {
        scanf("%s",m);
        fp=fopen(m,"w");
    }
    else
    {
        fp=fopen("C:\\dqce.txt","w");
    }
    float a,v,vx,vy,t;
    float *pvx,*pvy;
    pvx=&vx;
    pvy=&vy;
    printf("what is a,v");
    scanf("%f%f",&a,&v);
    if (a>0&&a<180&&v>0)
    {
        VXY(a,v,pvx,pvy,fp);
        t=T(vy,fp);
    }
    else if (a<=0||a>=180||v<=0)
    {
        printf("wrong\nshould be");
        return (0);
    }
    location(vx,vy,t,fp);
    fclose(fp);
    getch();
    return;
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
        printf("x%d=%.3f  ",i,x);
        fprintf(fp,"x%d=%.3f  ",i,x);
        printf("y%d=%.3f  ",i,y );
        fprintf(fp,"y%d=%.3f  ",i,y );
        printf("t%d=%.3f  \n",i,time );
        fprintf(fp,"t%d=%.3f  \n",i,time );
    }
}
float VXY(float a,float v,float *pvx ,float *pvy,FILE *fp)
{
  *pvx=v*cos(a*pi/180);
  *pvy=v*sin(a*pi/180);
  printf("vx=%.3f  ",*pvx);
  fprintf(fp,"vx=%.3f  ",*pvx);
  printf("vy=%.3f  \n",*pvy);
  fprintf(fp,"vy=%.3f  \n",*pvy);
}
float T(float vy,FILE *fp)
{
    printf("TOF=%.3f\n",2*vy/9.81);
    fprintf(fp,"TOF=%.3f\n",2*vy/9.81);
    return (2*vy/9.81);
}

