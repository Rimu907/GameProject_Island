#include <stdio.h>
#include<math.h>
#define pi 3.1415926
/*int main()
{
    int i;
    int sum=0;
    for(i=1;i<=15;i=i+2)
    {
        sum=sum+i;
    }
    printf("%d",sum);
    return(0);
}
*/

/*void main ()
{
 float a,b,c;
 float s,A;
 scanf("%f%f%f",&a,&b,&c);
 s=(a+b+c)/2;
 A=sqrt(s*(s-a)*(s-b)*(s-c));
 printf("%.3f,%.3f",s,A);

}*/
/*
void main()
{
    char a;
    do
    {

    a = getchar();
    printf("%c",a);
    }
    while(a!='!');
}*/
/*void main()
{
    int a;
    scanf("%d",&a);
    switch(a)
    {
     case 1: printf("Happy First Birthday");break;
     case 17: printf("You can learn to drive");break;
     case 30: printf("Still young");break;
     case 40: printf("Getting older");break;
    }

}
*/
/*void main()
{
    float R1,R2,Av;
    printf("enter R1,R2");
    scanf("%f%f",&R1,&R2);
    Av=(R1+R2)/R1;
    printf("%.2f",Av);
}
*/
/*void main ()
{
  int i,a,b,c;
  float *pa,*pb,*pc;
  pa=&a;pb=&b;pc=&c;
   printf("Angle  Sine  COS  TAN\n");
   printf("---------------------------------------------------\n");
  for (i=0;i<=45;i=i+5)
  {
     *pa=sin(i*pi/180);
     *pb=cos(i*pi/180);
     *pc=tan(i*pi/180);
     printf("%3d   ",i);
     printf("%.2f  ",*pa);
     printf("%.2f   ",*pb);
     printf("%.2f  \n",*pc);
  }
}*/
/*void main ()
{
   int i;
   float a,b,c;
   printf("Angle  Sine  COS  TAN\n");
   printf("---------------------------------------------------\n");
  for (i=0;i<=45;i=i+5)
  {
     a=sin(i*pi/180);
     b=cos(i*pi/180);
     c=tan(i*pi/180);
     printf("%3d   ",i);
     printf("%.2f  ",a);
     printf("%.2f   ",b);
     printf("%.2f  \n",c);
  }
}
*/
/*void main ()
{
 float area(float a,float b,float c,float p);
 float a,b,c,p;
 printf("what is the a b c\n");
 scanf("%f%f%f",&a,&b,&c);
 area(a,b,c,p) ;
}
float area(float a,float b,float c,float p)
{
  p=(a+b+c)/2;
  printf("%.3f",sqrt((p*(p-a)*(p-b)*(p-c))));
  return(sqrt((p*(p-a)*(p-b)*(p-c))));
}
void main()
{
    int i;
    int sum=0;
    float rms;
    for(i=1;i<=5;i++)
    {
     sum=sum+i*i;
     rms=sqrt(sum/i);
    }
    printf("%.3f",rms);
}*/
/*void main()
{
    int i;
    int sum=1;
    for (i=1;i<=5;i++)
    {
        sum=sum*i;
    }
    printf("%d",sum);
}*/
/*void main()
{
  float rrr(float r1,float r2,float r3,float *rs,float *rp);
  float r1,r2,r3,rs,rp;
  scanf("%f%f%f",&r1,&r2,&r3);
  rrr(r1,r2,r3,&rs,&rp);
  printf("rs=%.3f,rp=%.3f",rs,rp);
}
   float rrr(float r1,float r2,float r3,float *rs,float *rp)
 {
     *rs=r1+r2+r3;
     *rp=(r1*r2*r3)/(r1*r2+r2*r3+r1*r3);
 }*/
 #include <stdio.h>
int main()
{
        char a[100];
		int i=0,
		    j=0;
        while((a[i++]=getchar())!='!')
		{
			if (a[i-1]=='\n') continue;
			switch(a[i-1])
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u': j++; printf("共按下 %d个键,共按下元音键%d个,元音占百分比%.3f%%\n",i,j,100.0*j/i);break;
            default: printf("共按下 %d个键,共按下元音键%d个,元音占百分比%.3f%%\n",i,j,100.0*j/i);
		}
		}
        return 0;
}
