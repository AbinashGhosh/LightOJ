//OM
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <utility>
#include <sstream>
#include <algorithm>
using  namespace  std;

#define  x first
#define  y second
#define  pb push_back
#define  mp make_pair
#define  PI (acos(-1.0))
#define  mem(a,b) memset(a,b,sizeof(a))
#define  Sort(x) sort(x.begin(),x.end())
#define  FOR(i, b, e) for(int i = b; i <= (int)(e); i++)
#define  FORR(i, b, e) for(int i = b; i >=(int)(e); i--)
#define  FORI(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define  pr(x) cout<<x<<"\n"
#define  prs(x) cout<<x<<" "
#define  pr2(x,y) cout<<x<<" "<<y<<"\n"
#define  pr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define  ppr(a) cout<<a.x<<" "<<a.y<<"\n"

typedef  long long ll;
typedef  pair <int, int> pii;
typedef  pair <double , double> pdd;
typedef  vector <int> vi;
typedef  vector <pii> vpii;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

#define  EPS 1e-9
#define  MAX 10007
vi edge[MAX];
int in[MAX];
int vis[MAX];

void DFS_visit(int u)
{
    vis[u]=1;
    for(int i=0;i<edge[u].size();++i)
    {
        int v=edge[u][i];
        if(vis[v]==0)
        {
            DFS_visit(v);
        }
    }
}
int main()
{
    int T,n,m,u,v;
    scanf("%d",&T);
    FOR(cs,1,T)
    {
        scanf("%d",&n);
        scanf("%d",&m);
        FOR(i,1,m)
        {
            scanf("%d %d",&u,&v);
            edge[u].pb(v);
            in[v]++;
        }
        vpii ver;
        FOR(i,1,n)ver.pb(mp(in[i],i));
        Sort(ver);
        int cnt=0;
        FOR(i,0,n-1)
        {
            if(!vis[ver[i].y])
            {
                pr2(ver[i].x,ver[i].y );
                cnt++;
                DFS_visit(ver[i].y);
            }
        }
        FOR(i,1,n)edge[i].clear();
        mem(vis,0);
        mem(in,0);
        printf("Case %d: %d\n",cs,cnt);
    }
    return 0;
}

