#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>

#include <iostream>
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

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1, 0, 1};
//int dy[]={0,1,1, 1, 0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1, 1, 2};
//int dy[]={1,2, 2, 1,-1,-2,-2,-1};//Knight Direction

int k,m,n;
int person[102],vt[1005],indeg[1005];
vi edge[1005];
void DFS_visit(int u)
{
    vt[u]=1;
    //pr(u);
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i];
        if(vt[v]==0)
        {
            DFS_visit(v);
        }
    }
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T,u,v;
    scanf("%d",&T);
    FOR(t,1,T)
    {
        scanf("%d%d%d",&k,&n,&m);
        FOR(i,1,k)
        scanf("%d",&person[i]);
        FOR(i,1,m)
        {
            scanf("%d%d",&u,&v);
            edge[u].pb(v);
        }
        int ans=n+1;
        FOR(i,1,k)
        {
            int count=0;
            mem(vt,0);
            DFS_visit(person[i]);
            FOR(j,1,n)
            {
                if(vt[j])
                {
                    count++;
                }
            }
            //pr(count);
            ans=min(ans,count);
        }
        printf("Case %d: %d\n",t,ans);
        FOR(i,0,n)
        edge[i].clear();
    }
    return 0;
}

