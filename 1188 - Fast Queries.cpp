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

#define MAX 100007
#define EPS 1e-9
int a[MAX],tree[MAX*3];

int query(int n,int b,int e,int i,int j)
{
    if(i>j)return 0;
    if(i>e||j<b)return 0;
    if(i<=b&&e<=j)return tree[n];
    int l=n<<1;
    int m=(b+e)/2;
    return query(l,b,m,i,j)+query(l+1,m+1,e,i,j);
}
void update(int n,int b,int e,int i,int v)
{
    if(i>e||i<b)return;
    if(b==e){
        tree[n]+=v;
        return;
    }
    int l=n<<1;
    int m=(b+e)/2;
    update(l,b,m,i,v);
    update(l+1,m+1,e,i,v);
    tree[n]=tree[l]+tree[l+1];
}
pair<pii,int > q[MAX/2];
int vis[MAX];
int ans[MAX];
int main()
{
    //READ("in.in");
    //WRITE("out.out");
    int T,n,m;
    scanf("%d",&T);
    FOR(cs,1,T)
    {
        scanf("%d%d",&n,&m);
        FOR(i,1,n)scanf("%d",&a[i]);
        FOR(i,0,m-1){scanf("%d%d",&q[i].x.y,&q[i].x.x);q[i].y=i;}
        sort(q,q+m);
        int nichi=0;
        FOR(i,1,n)
        {
            update(1,1,n,i,1);
            if(vis[a[i]]){ update(1,1,n,vis[a[i]],-1);}
            vis[a[i]]=i;
            while(nichi<m&&i==q[nichi].x.x)
            {
                ans[q[nichi].y]=query(1,1,n,1,q[nichi].x.x);
                ans[q[nichi].y]-=query(1,1,n,1,q[nichi].x.y-1);
                nichi++;
            }
        }
        mem(tree,0);
        mem(vis,0);
        printf("Case %d:\n",cs);
        FOR(i,0,m-1)printf("%d\n",ans[i]);
    }

    return 0;
}
