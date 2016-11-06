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
#define M 10000007
bool marked[M];
void sieve(int n)
{
    marked[1]=true;
    for (int i=3;i*i<=n;i+=2)
        if (marked[i]==false)   // i is a prime
            for(int j=i*i,k=i<<1;j<=n;j+=k)
                marked[j]=true;
}
bool isPrime(int n)
{
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    return marked[n] == false;
}
int  num[664590];
int main()
{
    //READ("out.out");
    //WRITE("out.out");
    sieve(10000001);
    int c=0;
    for(int i=1;i<=10000007;i++)if(isPrime(i))num[c++]=i;
    int T,n;
    scanf("%d",&T);
    FOR(cs,1,T)
    {
        scanf("%d",&n);
        int ans=0;
        FOR(i,0,c)
        {
            if(num[i]>n/2)break;
            if(isPrime(n-num[i])&&n-num[i]>=2)
                ans++;
        }
        printf("Case %d: %d\n",cs,ans);
    }
    return 0;
}





