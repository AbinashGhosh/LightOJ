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

#define MAX 150010
#define EPS 1e-9

int tree[MAX*4],prop[MAX*4];

int query(int n,int b,int e,int i,int j,int c=0)
{
    if(i>e||j<b)return 0;
    if(i<=b&&e<=j)return tree[n]+(e-b+1)*c;
    int l=n<<1;
    int m=(b+e)/2;
    return query(l,b,m,i,j,c+prop[n])
          +query(l+1,m+1,e,i,j,c+prop[n]);
}
void update(int n,int b,int e,int i,int j,int v)
{
    if(i>e||j<b)return;
    if(b>=i&&e<=j){
        tree[n]+=(e-b+1)*v;
        prop[n]+=v;
        return;
    }
    int l=n<<1;
    int m=(b+e)/2;
    update(l,b,m,i,j,v);
    update(l+1,m+1,e,i,j,v);
    tree[n]=tree[l]+tree[l+1]+(e-b+1)*prop[n];
}
pii line[50005];
int q[50005];
map<int,int > Map;
int main()
{
    //READ("in.in");
    //WRITE("out.out");
    int T,n,Q;
    scanf("%d",&T);
    FOR(cs,1,T)
    {
        scanf("%d%d",&n,&Q);
        FOR(i,1,n)
        {
            scanf("%d%d",&line[i].x,&line[i].y);
            Map[line[i].x]=1;
            Map[line[i].y]=1;
        }
        FOR(i,1,Q)
        {
            scanf("%d",&q[i]);
            Map[q[i] ]=1;
        }
        int idx=0;
        FORI(i,Map)i->y=++idx;
        FOR(i,1,n)update(1,1,idx,Map[line[i].x],Map[line[i].y],1);
        printf("Case %d:\n",cs);
        FOR(i,1,Q)printf("%d\n",query(1,1,idx,Map[q[i] ],Map[q[i] ]));
        Map.clear();
        mem(tree,0);
        mem(prop,0);
    }
    return 0;
}
