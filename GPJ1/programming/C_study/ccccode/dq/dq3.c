#include<stdio.h>
#define pi 3.14159265359
int main()
{
    float location(float vx,float vy,float t,FILE *fp);
    float VXVY(float a,float v,float *pvx,float *pvy,FILE *fp);
    float T(float vy,FILE *fp);
    int n;
    FILE *fp;
    char m[50];
    printf("enter 1 or 2");
    scanf("%d",&n);
    if (n==1)
    {
        scanf("%s",m);
        fp=fopen(m,"w");
    }
    else
    {
        fp=fopen("C:\\ddqq1.txt","w");
    }
    float a,v,vx,vy,t;
    float *pvx, *pvy;
    pvx=&vx;pvy=&vy;
    printf("what is the a ,v \n");
    scanf("%f%f",&a,&v);
    if (a>0&&a<180&&v>0)
    {
        VXVY(a,v,pvx,pvy,fp);
        t=T(vy,fp);
    }
    else if(a<=0||a>=180||v<=0)
    {
        printf("wrong ,the right data should be :");
        return (0);
    }
    location(vx,vy,t,fp);
    fclose(fp);
    return(0);
}
    float VXVY(float a,float v,float *pvx,float *pvy,FILE *fp)
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
        printf("TOF=%.3f  \n",2*vy/9.81);
        fprintf(fp,"TOF=%.3f  \n",2*vy/9.81);
        return(2*vy/9.81);
    }
    float location(float vx,float vy,float t,FILE *fp)
    {
        int i;
        float x,y;
        float time;
        for(i=1;i<=10;i++)
        {
            x=t*i/10*vx;
            y=vy*t*i/10-4.905*t*i/10*t*i/10;
            time=t*i/10;
            printf("x%d=%.3f  ",i,x);
            fprintf(fp,"xd%=%.3f  ",i,x);
            printf("y%d=%.3f  ",i,y);
            fprintf(fp,"y%d=%.3f  ",i,y);
            printf("t%d=%.3f  \n",i,time);
            fprintf(fp,"t%d=%.3f  \n",i,time);
        }
    }
