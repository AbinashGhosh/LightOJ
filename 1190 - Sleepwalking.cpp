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

/// Cross Product : ab x ac
inline int cross(pii a, pii b, pii c)
{
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}

/// Point k is in Segment Point i to j
inline bool onsegment(pii i,pii j,pii k)
{
    return (min(i.x,j.x)<=k.x&&k.x<=max(i.x,j.x)&&
            min(i.y,j.y)<=k.y&&k.y<=max(i.y,j.y));
}

///Point inside a polygon(with Boundry Case) r always double
bool PIP(vpii p,pdd r)
{
    int n=p.size();
    bool c=false;
    for (int i = 0, j = n-1; i < n; j = i++)
    {
        if(onsegment(p[i],p[j],r)&&!cross(p[i],p[j],r)) return true;//For the boundry case
        if (((p[i].y>r.y) != (p[j].y>r.y))&&
            (r.x<((p[j].x-p[i].x)*(r.y-p[i].y)/(p[j].y-p[i].y)*1.+p[i].x)) )
            c = !c;
    }
    return c;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T,n,a,b,q;
    vpii p;
    scanf("%d",&T);
    FOR(t,1,T)
    {
        scanf("%d",&n);
        FOR(i,1,n)
        {
            scanf("%d%d",&a,&b);
            p.pb(mp(a,b));
        }
        scanf("%d",&q);
        printf("Case %d:\n",t);
        FOR(i,1,q)
        {
            scanf("%d%d",&a,&b);
            if(PIP(p,mp(a,b)))
                printf("Yes\n");
            else printf("No\n");
        }
        p.clear();
    }
    return 0;
}
