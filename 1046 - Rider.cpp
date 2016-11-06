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
int dx[]={1,+1,2,+2,-1,-1,-2,-2};
int dy[]={2,-2,1,-1,+2,-2,+1,-1};//k direction

#define  EPS 1e-9
#define  MAX 100007

int d[12][12],R,C;
int g[12][12];
int BFS2D(int x,int y,int knight)
{
    int gc,gr,res=0;
    memset(d,-1,sizeof(d));
    queue<pii>Q;
    Q.push(mp(x,y));
    d[x][y]=0;
    while(!Q.empty())
    {
        pii u=Q.front();
        Q.pop();
        if(g[u.x][u.y]!='.')
        {
            knight--;
            int mov=g[u.x][u.y]-'0';
            res+=ceil(d[u.x][u.y]*1./mov*1.);
        }
        for(int i=0; i<8; i++)
        {
            gr=u.x+dx[i];
            gc=u.y+dy[i];
            if(gr>=0&&gr<R&&gc>=0&&gc<C&&d[gr][gc]==-1)
            {
                Q.push(mp(gr,gc));
                d[gr][gc]=d[u.x][u.y]+1;
            }
        }
    }
    if(!knight){
            return res;
    }
    return 1000000000;
}
int main()
{
    int T,n,m;
    scanf("%d",&T);
    FOR(cs,1,T)
    {
        getchar();
        getchar();
        scanf("%d%d",&n,&m);
        R=n,C=m;
        int knight=0;
        FOR(i,0,n-1)
        {
            getchar();
            FOR(j,0,m-1){
                scanf("%c",&g[i][j]);
                if(g[i][j]!='.')knight++;
            }
        }
        int ans=1000000000;
        FOR(i,0,n-1)
        {
            FOR(j,0,m-1)
            {
                ans=min(ans,BFS2D(i,j,knight));
            }
        }
        if(ans==1000000000)ans=-1;
        printf("Case %d: %d\n",cs,ans);

    }
    return 0;
}
/*
4

3 2
..
2.
..

3 3
1.1
...
..1

10 10
..........
.2....2...
......2...
1.........
...2.1....
...1......
..........
.......21.
..........
..........

1 4
1..1

2

4 5
.....
.....
3....
....1

10 10
9133632343
5286698232
8329333369
5425579782
4465864375
8192124686
3191624314
5198496853
1638163997
6457337215
*/
