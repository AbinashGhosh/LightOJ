
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

#define MAX 100007
#define EPS 1e-9
ll gcdll(ll a, ll b){
  if(b == 0) return a;
  return gcd(b, a%b);
}

ll divisor(ll lcm,ll L)
{
    ll ans=1;
    for(long long  i=2;i*i<=L;i+=2)
    {
        if(L%i==0)
        {
            while(L%i==0)L/=i,ans*=i;
            while(lcm%i==0)lcm/=i,ans*=i;
        }
        if(i==2)i--;
    }
    if(L>1)
    {
        while(lcm%L==0)lcm/=L,ans*=L;
        ans*=L;
    }
    return ans;
}
int main()
{
    //READ("in.in");
    //WRITE("out.out");
    int T,n,a,b;
    ll L;
    scanf("%d",&T);
    FOR(cs,1,T)
    {
        scanf("%d%d%lld",&a,&b,&L);
        ll gcd=gcdll(a,b);
        ll lcm=(1ll*a*b);
        //pr(lcm);
        lcm/=gcd;

        if(L%lcm==0)
            printf("Case %d: %lld\n",cs,divisor(lcm,L/lcm));
        else
            printf("Case %d: impossible\n",cs);

    }
    return 0;
}




