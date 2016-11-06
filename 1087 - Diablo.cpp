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

#define MAX 150007
#define EPS 1e-9

int arr[MAX],tree[MAX*4];

void init(int n,int b,int e)
{
    if(b==e){
        tree[n]=arr[b];
        return;
    }
    int l=n<<1;
    int m=(b+e)/2;
    init(l,b,m);
    init(l+1,m+1,e);
    tree[n]=tree[l]+tree[l+1];
}
int query(int n,int b,int e,int v)
{
    tree[n]--;
    if(b==e)return b;
    int l=n<<1;
    int m=(b+e)/2;
    if(v<=tree[l])
    return query(l,b,m,v);
    else
    query(l+1,m+1,e,v-tree[l]);
}
void update(int n,int b,int e,int i,int v)
{
    if(i>e||i<b)return;
    if(b==e){
        tree[n]=v;
        return;
    }
    int l=n<<1;
    int m=(b+e)/2;
    update(l,b,m,i,v);
    update(l+1,m+1,e,i,v);
    tree[n]=tree[l]+tree[l+1];
}
int main()
{
    //READ("in.in");
    //WRITE("out.out");
    int T,n,q,x;
    char c;
    scanf("%d",&T);
    FOR(cs,1,T)
    {
        scanf("%d%d",&n,&q);
        int m=n+q,cnt=n;
        vi id;
        FOR(i,1,n)
        {
            scanf("%d",&x);
            update(1,1,m,i,1);
            id.pb(x);
        }
        printf("Case %d:\n",cs);
        FOR(i,1,q)
        {
            getchar();
            scanf("%c %d",&c,&x);
            if(c=='a')
            {
                n++;
                cnt++;
                id.pb(x);
                update(1,1,m,n,1);
            }
            else
            {
                if(x<=cnt){
                int getid=query(1,1,m,x);
                printf("%d\n",id[getid-1]);
                cnt--;
                }
                else printf("none\n");

            }
        }
        mem(tree,0);
    }
    return 0;
}
/*
2
5 5
6 5 3 2 1
c 1
c 1
a 20
c 4
c 4
2 1
18811 1991
c 1
*/
