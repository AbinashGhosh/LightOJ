//Abinash Ghosh
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
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
#include <ctime>
#include <cassert>
#include <limits>
using  namespace  std;

#define PI acos(-1.0)
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define Sort(x) sort(x.begin(),x.end())
#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORR(i, b, e) for(int i = b; i >= e; i--)
#define FORI(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define pr(x) cout<<x<<"\n"
#define pr2(x,y) cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n";
#define ppr(a) cout<<a.x<<" "<<a.y<<"\n"
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

#define MAX 1000007
#define EPS 1e-9
#define MOD 1000003
ll fact[MAX];
void fac(int n)
{
    fact[0]=1;
    FOR(i,1,n)
    fact[i]=(i*fact[i-1])%1000003;
}
ll modInverse(ll a, int p)
{

    if(p == 0)
    {
        return 1;
    }

    int half = p/2;

    ll res = modInverse(a, half);
    res = (res*res) % MOD;
    if((p & 1) > 0)
    {
        res = (res*a)%MOD;
    }
    return res;
}
ll BigMod(ll B,ll P,ll M){
    ll R=1;B=B%M;
    while(P>0){
        if(P&1)R=(R*B)%M;
        P/=2,B=(B*B)%M;}
    return R%M;
}
int main()
{
    //READ("in.in");
    //WRITE("out.out");
    int T,n,k;
    ll m,a,b;
    fac(MAX-2);
    scanf("%d",&T);
    FOR(cs,1,T)
    {
        scanf("%d %d",&n,&k);
        ll temp=(fact[k]*fact[n-k])%1000003;
        temp=BigMod(temp,MOD-2,MOD);
        ll s=fact[n]*temp;
        printf("Case %d: %lld\n",cs,s%1000003);
    }
    return 0;
}





