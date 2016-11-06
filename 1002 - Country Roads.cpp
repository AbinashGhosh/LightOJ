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
vi g[505];
int w[505][505],d[505];
struct node{
    int u,w;
    node(int a,int b){
        u=a,w=b;
    }
    bool operator<(const node &p)const{
        return w>p.w;
    }
};
void dijkstra(int s)
{
    mem(d,-1);
    priority_queue<node>Q;
    d[s]=0;
    Q.push(node(s,0));
    while(!Q.empty())
    {
        node top=Q.top();Q.pop();
        int u=top.u;
        for(int i=0;i<(int)g[u].size();i++)
        {
            int v=g[u][i];
            int temp=max(d[u],w[u][v]);
            if(temp<d[v]||d[v]==-1)
            {
                d[v]=temp;
                Q.push(node(v,d[v]));
            }
        }
    }

}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T,u,v,W,n,m,s;
    scanf("%d",&T);
    FOR(t,1,T)
    {
        scanf("%d%d",&n,&m);
        mem(w,-1);
        FOR(i,1,m)
        {
            scanf("%d%d%d",&u,&v,&W);
            if(w[u][v]==-1||w[u][v]>W)
            {
                if(w[u][v]==-1)
                {
                    g[u].pb(v);
                    g[v].pb(u);
                }
                w[u][v]=W;
                w[v][u]=W;
            }
        }
        scanf("%d",&s);
        dijkstra(s);
        printf("Case %d:\n",t);
        FOR(i,0,n-1)
        {
            if(d[i]!=-1)
            printf("%d\n",d[i]);
            else
            printf("Impossible\n");
            d[i]=0;
            g[i].clear();
        }
    }
    return 0;
}
