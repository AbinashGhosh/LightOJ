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
#define pr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n";
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
// scanf("%d",&n);
ll dig[20];
ll dp[20][20];
//pre false samne sob 0 thake
// flag false given num er digit age use kore thakle
ll solve2(int pos,int cnt,int pre,int flag)
{
    if(pos==0)return (ll)cnt;
    if(pre&&flag&&dp[pos][cnt]!=-1)return dp[pos][cnt];
    int m=flag?9:dig[pos];
    ll ans=0;
    FOR(i,0,m)
    {
       ans+=solve2(pos-1,cnt+(pre&&i==0),pre||i,flag||i<m);
    }
    if(pre&&flag)dp[pos][cnt]=ans;
    return ans;
}
ll solve(ll n)
{
    mem(dp,-1);
    int len=0;
    while(n)
    {
        dig[++len]=n%10;
        n/=10;
    }
    return solve2(len,0,0,0);
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T;
    ll n,a,b;
    scanf("%d",&T);
    FOR(t,1,T)
    {
        scanf("%lld%lld",&a,&b);
        ll ans2=solve(a-1);
        ll ans=solve(b)-ans2;
        //pr2(ans2,ans);
        printf("Case %d: %lld\n",t,ans+(a==0));
    }
    return 0;
}



