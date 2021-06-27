#include <stdio.h>
void main()
{
  int s[5];
  int sum;
  sum=0;
  float ave ;
  int i;
  printf("Enter 5 numbers\n");
  for(i=0;i<5;i++)
  {
    scanf("%d",&s[i]);
  }
    for(i=0;i<5;i++)
  {
    sum=sum+s[i];
  }
      ave = sum/5;
     printf("%f",ave);
     return;
}
