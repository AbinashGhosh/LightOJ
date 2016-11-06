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
int dp[(1<<14)+5],n,p[15][15];
int solve(int m)
{
    //pr(m);
    if(checkB(m+1,n))return 0;
    if(dp[m]!=-1)return dp[m];
    int ret=10000000;
    FOR(i,0,n-1)
    {
        int ans=p[i][i];
        if(!checkB(m,i))
        {
            FOR(j,0,n-1)
            {
                if(i!=j&&checkB(m,j))
                ans+=p[i][j];
            }
            ret=min(ret,ans+solve(setB(m,i)));
        }
    }
    //pr(ret);
    return dp[m]=ret;
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
        scanf("%d",&n);
        FOR(i,0,n-1)
        {
            FOR(j,0,n-1)
            {
                scanf("%d",&p[i][j]);
            }
        }
        ll ans=solve(0);
        printf("Case %d: %lld\n",t,ans);
    }
    return 0;
}


