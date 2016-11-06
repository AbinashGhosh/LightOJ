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

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1, 0, 1};
//int dy[]={0,1,1, 1, 0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1, 1, 2};
//int dy[]={1,2, 2, 1,-1,-2,-2,-1};//Knight Direction
int m,n,q,best;
char g[505][505];
bool vt[505][505];
void DFS_visit(int r,int c)
{
    if(vt[r][c]||g[r][c]=='#'||r>=m||c>=n||r<0||c<0)return;
    vt[r][c]=true;
    if(g[r][c]=='C')best++;
    FOR(i,0,3)
       DFS_visit(r+dx[i],c+dy[i]);
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T,row,col;
    scanf("%d",&T);
    FOR(t,1,T)
    {
        scanf("%d",&m);
        scanf("%d",&n);
        scanf("%d\n",&q);
        FOR(i,0,m-1)
        {
            scanf("%s",g[i]);
        }
        printf("Case %d:\n",t);
        FOR(i,1,q)
        {
            scanf("%d",&row);
            scanf("%d",&col);
            mem(vt,false);
            best=0;
            DFS_visit(row-1,col-1);
            printf("%d\n",best);
        }
    }
    return 0;
}
/*

2
4 5 2
..#..
.C#C.
##..#
..C#C
1 1
4 1
4 5 2
.C#.C
.C#C.
##..#
.CC#C
1 1
4 1
*/

