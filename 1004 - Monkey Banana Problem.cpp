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
int n;
ll dp[101][101],a[101][101];
ll solve(int r,int c)
{
    if(r<1||r>n||c<1||c>n)return 0;
    if(dp[r][c]!=-1)return dp[r][c];
    ll ans=solve(r,c-1)+a[r][c];
    ans=max(ans,solve(r+1,c)+a[r][c]);
    return dp[r][c]=ans;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T;
    scanf("%d",&T);
    FOR(i,1,T)
    {
        mem(dp,-1);
        scanf("%d",&n);
        int r=1,c=n+1,x,y;
        FOR(j,1,2*n-1)
        {
            if(c>1)c--;
            else r++;
            x=r,y=c;
            while(x<=n&&y<=n)
            {
                scanf("%d",&a[x][y]);
                x++;y++;
            }
            //puts("E");
        }
        //pr2(r,c);
        ll ans=solve(1,n);
        printf("Case %d: %lld\n",i,ans);
    }
    return 0;
}

