#include<stdio.h>
int main()
{
 int a,b,sum;
 int i;
 int c[10];
 scanf("%d%d",&a,&b);
 sum=a+b;
 if(sum<0)
    { 
      sum=-sum;
      printf("-");
    }
 if(sum==0)
   printf("0");
 for(i=0;sum;i++)
   {
     c[i]=sum%10;
     sum/=10;
   }
 i--;
 
 for(;i>=0;i--)
   {
   	printf("%d",c[i]);
	if(i%3==0&&i!=0)
	printf(","); 
   }
 return 0;
} 
