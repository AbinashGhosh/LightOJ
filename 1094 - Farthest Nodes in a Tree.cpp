/**************************************************
    _|||||_     -||||||||_    -|||    |||-   _|
   _||    ||_    |||    ||     |||    |||   |||
   |||    |||    |||    ||     |||    |||   |||
   |||    |||    |||___||-     |||____|||   |||
   ||||||||||    |||---||_     |||----|||   |||
   |||    |||    |||    ||     |||    |||   |||
   |||    |||    |||    ||     |||    |||   |||
  _|||    |||_  _||||||||-    _|||    |||_  |-
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

#define MAX 30007
#define EPS 1e-9
vi edge[MAX];
vi cost[MAX];
int d[2][MAX];
int vis[MAX];
pii MX;
void DFS(int s,int na)
{
    vis[s]=1;
    FOR(i,0,(int )edge[s].size()-1)
    {
        int v=edge[s][i];
        if(!vis[v])
        {
            d[na][v]=d[na][s]+cost[s][i];
            if(d[na][v]>MX.x){
                MX=mp(d[na][v],v);
            }
            DFS(v,na);
        }
    }
}
int main()
{
    //READ("in.in");
    //WRITE("out.out");
    int T,u,v,w,n;
    scanf("%d",&T);
    FOR(cs,1,T)
    {
        scanf("%d",&n);
        FOR(i,1,n-1)
        {
            scanf("%d%d%d",&u,&v,&w);
            edge[u].pb(v);
            cost[u].pb(w);
            edge[v].pb(u);
            cost[v].pb(w);
        }
        MX=mp(0,0);mem(vis,0);d[0][0]=0;
        DFS(0,0);
        int ffn=MX.y;

        MX=mp(0,0);mem(vis,0);d[0][ffn]=0;
        DFS(ffn,0);
        int sfn=MX.y;

        MX=mp(0,0);mem(vis,0);d[1][sfn]=0;
        DFS(sfn,1);

        printf("Case %d:\n",cs);
        FOR(i,0,n-1)
        {
            printf("%d\n",max(d[0][i],d[1][i]));
            edge[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
