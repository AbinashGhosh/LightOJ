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
#define MAX 30005
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

vi edge[MAX],cost[MAX];
int vt[MAX],best;
int DFS_visit(int u)
{
    //pr2(u,chk);
    int ans=0,ans1=0,temp;
    for(int i=0;i<edge[u].size();i++)
    {
        if(vt[edge[u][i]]==0)
        {
            vt[edge[u][i]]=1;
            temp=cost[u][i]+DFS_visit(edge[u][i]);
           // pr(temp);
            if(ans<=temp)
            {
                ans1=ans;
                ans=temp;
            }
            else if(ans1<temp)
                ans1=temp;
            //pr2(ans,ans1);
            best=max(ans+ans1,best);
        }
    }
   // best=min(ans+ans1,best);
    return ans;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T,u,v,n,w;
    scanf("%d",&T);
    FOR(t,1,T)
    {
        scanf("%d",&n);
        FOR(i,1,n-1)
        {
            scanf("%d%d%d",&u,&v,&w);
            edge[u].pb(v);
            edge[v].pb(u);
            cost[v].pb(w);
            cost[u].pb(w);
        }
        int ans=0;
        best=0;
        vt[0]=1;
        ans=DFS_visit(0);
        printf("Case %d: %d\n",t,best);
        FOR(i,0,n-1){
        edge[i].clear();
        cost[i].clear();
        vt[i]=0;
        }
    }
     return 0;
}

