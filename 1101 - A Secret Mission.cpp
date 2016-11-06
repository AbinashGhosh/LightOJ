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

#define MAX 50017
#define EPS 1e-9

struct  E
{
    int u,v,w;

};
bool comp(E a,E b){
    return a.w<b.w;
}
vector<E>edgel;
vi edge[MAX];
vi cost[MAX];
int dep[MAX];
//int val[MAX];
int par[18][MAX];
int mxw[18][MAX];
int find_res(int r)
{
    return (par[0][r]==r)?r:par[0][r]=find_res(par[0][r]);
}
void MST(int n)
{
    int cnt=0;
    sort(edgel.begin(),edgel.end(),comp);
    FOR(i,1,n)par[0][i]=i;//val[i]=1;
    FOR(i,0,(int)edgel.size()-1)
    {
        int u=find_res(edgel[i].u);
        int v=find_res(edgel[i].v);
        if(u!=v)
        {
           // par[0][u]=v;
            if(u<v)
            {
                par[0][v]=u;
              //  val[u]+=val[v];
            }
            else
            {
                par[0][u]=v;
              //  val[v]+=val[u];
            }
            edge[edgel[i].u].pb(edgel[i].v);
            edge[edgel[i].v].pb(edgel[i].u);
            cost[edgel[i].u].pb(edgel[i].w);
            cost[edgel[i].v].pb(edgel[i].w);
            cnt++;
            if(cnt==n-1)break;
        }
    }
}
void DFS(int n,int depth,int prev,int dist)
{

    par[0][n]=prev;
    dep[n]=depth;
    mxw[0][n]=dist;
    //printf("( ");
    FOR(i,0,(int)edge[n].size()-1)
    {
        if(prev!=edge[n][i])
        {
            // printf(" %d ",edge[n][i]);
            DFS(edge[n][i],depth+1,n,cost[n][i]);
        }
    }
    // printf(" )");
}
void LCA_pre(int n)
{
    int x,y;
    for(int i=1; 1<<i <=n; i++)
        FOR(j,1,n)
        if(par[i-1][j]!=-1)
        {
            par[i][j]=par[i-1][par[i-1][j]];
            x=mxw[i-1][j];
            y=mxw[i-1][par[i-1][j]];
            if(par[i][j]!=-1)
                mxw[i][j]=max(x,y);
            // printf("%d - ",1<<i);
            // pr3(j,par[i][j],mxw[i][j]);
        }
}
int  LCA_query(int u,int v)
{
    if(dep[u]<dep[v])swap(u,v);
    int log=1;
    while((1<<(log+1))<=dep[u])log++;
    FORR(i,log,0)
    if(dep[u]-(1<<i)>=dep[v])u=par[i][u];
    if(u==v)return u;
    FORR(i,log,0)
    if(par[i][u]!=-1&&par[i][u]!=par[i][v])
        u=par[i][u],v=par[i][v];
    return par[0][u];
}
int maxwe(int u,int v)
{
    if(u==v)return 0;
    int ans=0;
    int w=dep[u]-dep[v];
    // pr3(u,v,w);
    FORR(i,17,0)
    if(w-(1<<i)>=0)
    {
        ans=max(ans,mxw[i][u]);
        u=par[i][u],w-=(1<<i);
    }
    return ans;
}
int main()
{
    //READ("in.in");
    //WRITE("out.out");
    int T,n,m,u,v;
    scanf("%d",&T);
    E g;
    FOR(cs,1,T)
    {
        scanf("%d%d",&n,&m);
        edgel.clear();
        FOR(i,1,n)
        {
            edge[i].clear();
            cost[i].clear();
            FOR(j,0,17)par[j][i]=-1;
        }
        FOR(i,1,m)
        {
            scanf("%d%d%d",&g.u,&g.v,&g.w);
            edgel.pb(g);
        }
        MST(n);
        DFS(1,0,-1,0);
        LCA_pre(n);
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",cs);
        FOR(i,1,q)
        {
            scanf("%d%d",&u,&v);
            int lca=LCA_query(u,v);
            // pr(lca);
            int ans=max( maxwe(u,lca),maxwe(v,lca));
            printf("%d\n",ans);
        }
    }
    return 0;
}
