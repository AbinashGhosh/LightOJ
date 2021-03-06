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

#define MAX 5000004
#define EPS 1e-9
unsigned long long phi[MAX+2];
void calphi(int n)
{
    FOR(i,1,n)phi[i]=i;
    for(int i=2;i<=MAX;i+=2)phi[i]-=(phi[i]>>1);
    for(int i=3;i<=MAX;i+=2)
        if(phi[i]==i)
            for(int j=i;j<=MAX;j+=i)
                phi[j]-=(phi[j]/i);
    FOR(i,1,MAX)phi[i]=phi[i]*phi[i] +phi[i-1];
}
int main()
{
    //READ("in.in");
    //WRITE("out.out");
    int T,a,b;
    calphi(MAX);
    scanf("%d",&T);
    FOR(cs,1,T)
    {
        scanf("%d%d",&a,&b);
        ll ans=phi[b]-phi[a-1];
        printf("Case %d: %llu\n",cs,ans);
    }
    return 0;
}





