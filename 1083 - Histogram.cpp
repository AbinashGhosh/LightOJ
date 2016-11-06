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

#define MAX 30007
#define EPS 1e-9
int arr[MAX],tree[MAX*3];

void init(int n,int b,int e)
{
    if(b==e){
        tree[n]=b;
        return;
    }
    int l=n<<1;
    int m=(b+e)/2;
    init(l,b,m);
    init(l+1,m+1,e);
    if(arr[tree[l]]<arr[tree[l+1]])
    tree[n]=tree[l];
    else
    tree[n]=tree[l+1];
}
int query(int n,int b,int e,int i,int j)
{
    if(i>e||j<b)return -1;
    if(i<=b&&e<=j)return tree[n];
    int l=n<<1;
    int m=(b+e)/2;
    int p,q;
    p=query(l,b,m,i,j),q=query(l+1,m+1,e,i,j);
    if(p==-1)return q;
    if(q==-1)return p;
    if(arr[p]<arr[q])return p;
    return q;
}
int N;
int solve(int l,int r)
{
    if(l>r)return 0;
    int mn=query(1,1,N,l,r);
    return max(arr[mn]*(r-l+1),max(solve(l,mn-1),solve(mn+1,r) ) );
}
int main()
{
    //READ("in.in");
    //WRITE("out.out");
    int T,n;
    scanf("%d",&T);
    FOR(cs,1,T)
    {
        scanf("%d",&n);N=n;
        FOR(i,1,n)scanf("%d",&arr[i]);
        init(1,1,n);
        printf("Case %d: %d\n",cs,solve(1,n));
    }
    return 0;
}
