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
    ll dp[26][6*25+1];
ll gcdll(ll a , ll b)
{
     return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    FOR(i,1,6)dp[1][i]=1;
    FOR(i,1,23)
    {
        FOR(j,i,6*i)
        {
            FOR(k,1,6)
            dp[i+1][j+k]+=dp[i][j];
        }
    }
    int T,n,x;
    scanf("%d",&T);
    FOR(t,1,T)
    {
        scanf("%d%d",&n,&x);
        ll nem=0,dem=1;
        FOR(i,1,n)dem*=6;
        FOR(i,x,6*n)nem+=dp[n][i];
        ll g=gcd(nem,dem);
        nem/=g;
        dem/=g;
        printf("Case %d: %lld",t,nem);
        if(dem!=1)printf("/%lld\n",dem);
        else printf("\n");
    }
    return 0;
}



