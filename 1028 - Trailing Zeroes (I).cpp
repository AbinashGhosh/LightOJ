
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
bool marked[MAX];
int primes[80004],K;
void sieve(int n)
{
    marked[1]=true;
    for (int i=3;i<=1002;i+=2)
        if (marked[i]==false)   // i is a prime
            for(int j=i*i,k=i<<1;j<=n;j+=k)
                marked[j]=true;
    primes[0]=2;
    int k=0;
    for (int i=3;i<=n;i+=2)if(!marked[i])primes[++k]=i;
    K=k;
}
void sieve2()
{
    int c1=0,k;
      primes[c1++]=2;
    marked[2]=1;
    for(int i=3;i<1000000;i+=2) marked[i]=1;
    for(int i=3;i<1000000;i+=2) {
        if(marked[i]) {
            primes[c1++] = i;
            k=i<<1;
            for(int j=2*i;j<1000000;j+=k) marked[j] = 0;
        }
    }
    K=c1-1;
}
ll countDDivisor(ll n) {
  ll divisor = 1;
  for (int i = 0; i <=K&&primes[i]*primes[i]*1ll<=n; i++) {
    if (n % primes[i] == 0) {
      ll cnt = 1;
      while (n % primes[i] == 0) {
        n /= primes[i];
        cnt++;
      }
      divisor *= cnt;
    }
  }if(n!=1)divisor*=2;
  return divisor;
}
int main()
{
    //READ("in.in");
    //WRITE("out.out");
    int T,p,l;
    ll q;
    //sieve(1000004);
    sieve2();
    scanf("%d",&T);
    FOR(cs,1,T)
    {
        scanf("%lld",&q);
        ll ans= countDDivisor(q)-1;
        printf("Case %d: %lld\n",cs,ans);
    }
    return 0;
}




