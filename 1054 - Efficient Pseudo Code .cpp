/**************************************************
    _¦¦¦¦¦¦_    ¯¦¦¦¦¦¦¦¦_    ¯¦¦¦    ¦¦¦¯   _¦
   _¦¦    ¦¦_    ¦¦¦    ¦¦     ¦¦¦    ¦¦¦   ¦¦¦
   ¦¦¦    ¦¦¦    ¦¦¦    ¦¦     ¦¦¦    ¦¦¦   ¦¦¦
   ¦¦¦    ¦¦¦    ¦¦¦___¦¦¯     ¦¦¦____¦¦¦   ¦¦¦
   ¦¦¦¦¦¦¦¦¦¦    ¦¦¦¯¯¯¦¦_     ¦¦¦¯¯¯¯¦¦¦   ¦¦¦
   ¦¦¦    ¦¦¦    ¦¦¦    ¦¦     ¦¦¦    ¦¦¦   ¦¦¦
   ¦¦¦    ¦¦¦    ¦¦¦    ¦¦     ¦¦¦    ¦¦¦   ¦¦¦
  _¦¦¦    ¦¦¦_  _¦¦¦¦¦¦¦¦¯    _¦¦¦    ¦¦¦_  ¦¯
***************************************************/
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

#define MAX 100007
#define M 1000000007
#define EPS 1e-9

inline ll  bigmod(ll a,ll p,ll m ){
    ll res=1%m,x=a%m;
    while(p){
        if(p&1)res=(res*x)%m;
        x=(x*x)%m;p>>=1;}
    return res;
}

inline ll modInv(ll a,ll m){
    return bigmod(a,m-2,m);
}
bool mark[46400];
int prime[46400],prmcnt;
int  prime_gen(int n)
{
    for(int i=3;i*i<=n;i+=2)
        if(!mark[i])
            for(int j=i*i,k=i<<1;j<=n;j+=k)
            mark[j]=true;
    int k=0;
    prime[k++]=2;
    for(int i=3;i<=n;i+=2)if(!mark[i])prime[k++]=i;
    return k;
}
ll cal_sig(ll n,ll m)
{
    ll s=1;
    FOR(j,0,prmcnt-1)
    {
        ll i=prime[j];
        if(i*i>n)break;
        if(n%i==0)
        {
            int cnt=0;
            while(n%i==0)cnt++,n/=i;
            ll pw=m*cnt +1;
            s=(s*((((bigmod(i,pw,M)-1+M)%M)*modInv(i-1,M))%M))%M;
        }
    }
    ll pw=(m +1);
    if(n!=1)s=(s*((((bigmod(n,pw,M)-1+M)%M)*modInv(n-1,M))%M))%M;
    return s;
}
int main()
{
    //READ("in.in");
    //WRITE("out.out");
    int T;
    ll n,m;
    prmcnt=prime_gen(46400-3);

    scanf("%d",&T);
    FOR(cs,1,T)
    {
        scanf("%lld",&n);
        scanf("%lld",&m);
        printf("Case %d: %lld\n",cs,cal_sig(n,m));
    }

    return 0;
}
