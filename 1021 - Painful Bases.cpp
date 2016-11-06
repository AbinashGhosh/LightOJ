//Abinash Ghosh(Om)
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <sstream>
#include <algorithm>
using  namespace  std;

#define PI acos(-1.0)
#define MAX 10000007
#define EPS 1e-9
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define Sort(x) sort(x.begin(),x.end())
#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define pr(x) cout<<x<<"\n"
#define pr2(x,y) cout<<x<<" "<<y<<"\n"
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

typedef  long long ll;
typedef  pair <int, int> pii;
typedef  pair <double , double> pdd;
typedef  pair <ll , ll > pll;
typedef  vector <int> vi;
typedef  vector <pii> vpii;
typedef  vector <ll > vl;
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};
//int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

int setB(int N,int pos){return N=N|(1<<pos);}
bool checkB(int N,int pos){return (bool)(N&(1<<pos));}
int resetB(int N,int pos){return N=N&~(1<<pos);}

char s[17];
int n,k,l;
unsigned long long dp[(1<<16)+5][21],h[17];
unsigned long long solve(int lev,int m,int amount)
{
    //pr2(m,amount);
    if((m+1)==(1<<l+1))
    {
        if(amount%k==0)return 1;
        else return 0;
    }
    if(dp[m][amount]!=-1)return dp[m][amount];
    unsigned long long ret=0,temp;
    FOR(i,0,l)
    {
        if(!checkB(m,i))
        {
            //temp=(pow(n,lev)+EPS);
            ret+=solve(lev+1,setB(m,i),(h[i]+amount*n)%k);
        }
    }
    //pr(ret);
    return dp[m][amount]=ret;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T;
    scanf("%d",&T);
    FOR(t,1,T)
    {
        mem(dp,-1);
        scanf("%d%d\n",&n,&k);
        gets(s);
         l=strlen(s)-1;
        FOR(i,0,strlen(s)-1)
        {
            if(isalpha(s[i]))
                h[i]=s[i]-55;
            else h[i]=s[i]-'0';
        }
        unsigned long long ans=solve(0,0,0);
        printf("Case %d: %llu\n",t,ans);
    }
    return 0;
}

