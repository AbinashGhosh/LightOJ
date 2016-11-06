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

#define MAX 10007
#define EPS 1e-9
vi edge[MAX];
int dis[MAX];
int low[MAX];
int tim;
vector< pair< int, int > > Bridges;
void AP(int u,int par)
{
    dis[u]=low[u]=++tim;
    FOR(i,0,(int)edge[u].size()-1)
    {
        int v=edge[u][i];
        if(v==par)continue;
        if(dis[v])low[u]=min(low[u],dis[v]);
        else
        {
            AP(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>dis[u])Bridges.pb(mp(u,v));
        }
    }
}
int main()
{
    //READ("in.in");
    //WRITE("out.out");
    int T,n,e,a,b;
    scanf("%d",&T);
    FOR(cs,1,T)
    {

        scanf("%d",&n);
        FOR(i,1,n)
        {
            scanf("%d%*c%*c%d%*c",&a,&b);
            FOR(j,1,b)
            {
                scanf("%d",&e);
                edge[a].pb(e);
            }
        }
        tim=0;
        FOR(i,0,n-1)
        if(!dis[i])AP(i,-2);
        int ans=Bridges.size();
        FOR(i,0,ans-1)
            if(Bridges[i].x>Bridges[i].y)swap(Bridges[i].x,Bridges[i].y);
        sort(Bridges.begin(),Bridges.end());
        printf("Case %d:\n%d critical links\n",cs,ans);
        FOR(i,0,ans-1)
        {
            printf("%d - %d\n",Bridges[i].x,Bridges[i].y);
        }
        FOR(i,0,n)dis[i]=low[i]=0,edge[i].clear();
        Bridges.clear();

    }

    return 0;
}


