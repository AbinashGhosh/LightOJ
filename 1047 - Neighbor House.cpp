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

int c[21][4],n,dp[21][4];
ll solve(int i,int r)
{
    if(i>n)return 0;
    if(dp[i][r]!=-1)return dp[i][r];
    ll ret=2000000;
    FOR(k,1,3)
    {
        if(k!=r)
        ret=min(ret,solve(i+1,k)+c[i][k]);
    }
    return dp[i][r]=ret;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int t;
    scanf("%d",&t);
    FOR(i,1,t)
    {
        mem(dp,-1);
        scanf("%d",&n);
        FOR(j,1,n)
        {
            FOR(k,1,3)
            scanf("%d",&c[j][k]);
        }
        ll ans=solve(1,0);
        printf("Case %d: %lld\n",i,ans);
    }
    return 0;
}

