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

pair<ll,ll> p[10002];
int n;
///Polygon Area
inline ll pArea()
{
    ll area=0;
    for(int i=0;i<n;++i)
        area+=p[i].x*p[(i+1)%n].y-p[i].y*p[(i+1)%n].x;
    return abs(area);
}
int main()
{
    //READ("in.txt");

    freopen("1418 - trees.in", "r", stdin);
    freopen("1418 - trees.out", "w", stdout);
    int T;
    scanf("%d",&T);
    FOR(t,1,T)
    {
        scanf("%d",&n);
        FOR(i,0,n-1)
        scanf("%lld%lld",&p[i].x,&p[i].y);
        ll b=n;
        FOR(i,0,n-1)
        {
            if(p[i].x==p[(i+1)%n].x)
                b+=abs(p[i].y-p[(i+1)%n].y)-1;
            else if(p[i].y==p[(i+1)%n].y)
                b+=abs(p[i].x-p[(i+1)%n].x)-1;
            else
            {
                b+=(gcd(abs(p[i].x-p[(i+1)%n].x),abs(p[i].y-p[(i+1)%n].y))-1);
            }
        }
        ll area=pArea();
        //pr(area);
        ll inpoint=(area-b+2)/2;
        printf("Case %d: %lld\n",t,inpoint);
    }
    return 0;
}

