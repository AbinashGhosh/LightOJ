#include<stdio.h>
#include<string.h>
int main()
{
    long long int t,sum,a,c,i,l;
    char r[]="report",d[]="donate",ch[12];
    scanf("%lld",&c);
    for(i=1;i<=c;i++)
    {
    scanf("%lld",&t);
    l=0;sum=0;
    while(t--)
    {
        scanf("%s",ch);

        if(strcmp(ch,r)==0)
        {
            if(l==0)
            printf("Case %lld:\n",i);
            printf("%lld\n",sum);
            l=1;
        }
        else
        {
            scanf("%lld",&a);
            sum=sum+a;
        }
    }
    }
    return 0;
}

