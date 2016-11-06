//Abinash Ghosh(Om)
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
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
using  namespace  std;

#define PI acos(-1.0)
#define MAX 100007
#define EPS 1e-9
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
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

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};
//int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
int arr[MAX];
struct
{
    int s,p;
}tree[MAX*3];
int query(int n,int b,int e,int i,int j,int c=0)
{
    if(i>e||j<b)return 0;
    if(b>=i&&e<=j)return tree[n].s+c*(e-b+1);
    int l=n*2;
    int r=l+1;
    int m=(b+e)/2;
    int p1=query(l,b,m,i,j,c+tree[n].p*(e-b+1));
    int p2=query(r,m+1,e,i,j,c+tree[n].p*(e-b+1));
    return p1+p2;
}
void update(int n,int b,int e,int i,int j,int x)
{
    if(i>e||j<b)return;
    if(b>=i&&e<=j)
    {
        tree[n].s=c*(e-b+1);
    }
    int l=n*2;
    int r=l+1;
    int m=(b+e)/2;
    update(l,b,m,i,j,x);
    update(r,m,e,i,j,x);
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T,n,q,qt,a,b,v;
    scanf("%d\n",&T);
    FOR(t,1,T)
    {
        scanf("%d%d",&n,&q);
        FOR(i,1,q)
        {
            scanf("%d",&qt);
            if(qt==0)
            {
                scanf("%d%d%d",&a,&b,&v);
            }
            else
            {
                scanf("%d%d",&a,&b);
            }

        }
    }
    return 0;
}

