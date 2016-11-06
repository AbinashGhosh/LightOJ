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

int n;
vi edge[20005];
int  vt[20005];
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T,u,v;
    scanf("%d",&T);
    FOR(t,1,T)
    {
        scanf("%d",&n);
        mem(vt,0);
        FOR(i,1,n)
        {
            scanf("%d%d",&u,&v);
            edge[u].pb(v);
            edge[v].pb(u);
        }
        int ans=0;
        FOR(i,1,20000)
        {
            if(edge[i].size()>0&&!vt[i])
            {
                int vem=1,lik=0;
                queue<int>Q;
                Q.push(i);
                vt[i]=1;
                while(!Q.empty())
                {
                    u=Q.front();
                    Q.pop();
                    for(int j=0;j<edge[u].size();j++)
                    {
                        v=edge[u][j];
                        if(!vt[v])
                        {
                             Q.push(v);
                             vt[v]=3-vt[u];
                             if(vt[v]==1)vem++;
                             else lik++;
                        }
                    }
                }
                ans+=max(vem,lik);
            }
        }
        FOR(i,1,20000)
        edge[i].clear();
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}

