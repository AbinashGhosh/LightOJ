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
int T,row,col,ix,iy,cnt;
char g[22][22];
bool v[22][22];
void DFS_visit(int r,int c)
{
    if(row<=r||r<0||col<=c||c<0||g[r][c]=='#'||v[r][c])return;
    cnt++;
    v[r][c]=true;
    FOR(i,0,3)
        DFS_visit(r+dx[i],c+dy[i]);
    return;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    scanf("%d",&T);
    FOR(t,1,T)
    {
        scanf("%d%d",&col,&row);
        mem(v,false);
        FOR(i,0,row-1)
        {
            getchar();
            FOR(j,0,col-1)
            {
               scanf("%c",&g[i][j]);
               if(g[i][j]=='@')
                ix=i,iy=j;
            }
        }
        cnt=0;
        //pr2(ix,iy);
        DFS_visit(ix,iy);
        printf("Case %d: %d\n",t,cnt);
    }
    return 0;
}
/*
4
6 9
....#.
.....#
......
......
......
......
......
#@...#
.#..#.
11 9
.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........
11 6
..#..#..#..
..#..#..#..
..#..#..###
..#..#..#@.
..#..#..#..
..#..#..#..
7 7
..#.#..
..#.#..
###.###
...@...
###.###
..#.#..
..#.#..
*/
