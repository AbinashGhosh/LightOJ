/**************************************************
    _||||||_     ||||||||_    -|||    |||-   _|
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

#define MAX 100007
#define EPS 1e-9
int g[105][105];
int v[105],n;
int DFS(int s,int par)
{
    int ans=0;
    v[s]=1;
    FOR(i,1,n)
    {
        if(g[s][i]!=-1&&!v[i]&&i!=par){
            ans=g[s][i]+DFS(i,s);}
    }
    return ans;
}
int main()
{
    //READ("in.in");
    //WRITE("out.out");
    int T,u,vv,c;
    scanf("%d",&T);
    FOR(cs,1,T)
    {
        scanf("%d",&n);
        FOR(i,1,n)v[i]=0;
        FOR(i,1,n)
        FOR(j,1,n)g[i][j]=-1;

        FOR(i,1,n)
        {
            scanf("%d %d%d",&u,&vv,&c);
            g[u][vv]=0;
            g[vv][u]=c;
        }
        int ans=10000000;
        FOR(i,1,n)
        {
            if(g[1][i]!=-1)
            {
                        FOR(i,1,n)v[i]=0;
               // pr3(1,"->",i);
                ans=min(ans,g[1][i]+DFS(i,1));
            }
        }
        printf("Case %d: %d\n",cs,ans);
    }
    return 0;
}
