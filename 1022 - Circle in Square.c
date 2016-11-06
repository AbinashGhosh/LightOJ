#include<stdio.h>
#include<math.h>
int main()
{
    long long int i,t;
    double  result,r;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lf",&r);
        result=(4*r*r)-(2*acos(0.0)*r*r);
        printf("Case %lld: %.2f\n",i,result);
    }
    return 0;
}
