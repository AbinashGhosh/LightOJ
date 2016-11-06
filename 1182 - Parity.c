#include<stdio.h>
int main()
{
 long long int n,i,j,t,p;
 int count;
 scanf("%lld",&t);
 for(p=1;p<=t;p++)
 {
     scanf("%lld",&n);
     count=0;
     for(i=0;n>0;i++)
     {
         if(n%2==1)count++;
         n=n/2;

     }
     if(count%2==0)
     printf("Case %d: even\n",p);
     else
     printf("Case %d: odd\n",p);

 }


 return 0;
}



