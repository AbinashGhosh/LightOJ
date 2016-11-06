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
pii tree[MAX*3];
void init(int n,int b,int e)
{
    if(b==e)
    {
        tree[n].x=arr[b];
        tree[n].y=arr[b];
        return;
    }
    int l=n*2;
    int r=n*2+1;
    int m=(b+e)/2;
    init(l,b,m);
    init(r,m+1,e);
    tree[n].x=min(tree[l].x,tree[r].x);
    tree[n].y=max(tree[l].y,tree[r].y);
}
pii query(int n,int b,int e,int i,int j)
{
   // pr3(n,i,j);
    pii ans;
    if(i>e||j<b)return ans=mp(1000000000,-1);
    if(i<=b&&e<=j) return tree[n];
    int l=n*2;
    int r=n*2+1;
    int m=(b+e)/2;
    pii p1=query(l,b,m,i,j);
    pii p2=query(r,m+1,e,i,j);
    ans=mp(min(p2.x,p1.x),max(p1.y,p2.y));
    return ans;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T,n,q;
    scanf("%d\n",&T);
    FOR(t,1,T)
    {
        scanf("%d%d",&n,&q);
        FOR(i,1,n)scanf("%d",&arr[i]);
        init(1,1,n);
        int  ans=0;
        FOR(i,1,n-q+1)
        {
            //pr2(i,i+q-1);
            pii res=query(1,1,n,i,i+q-1);
            ans=max(ans,res.y-res.x);
        }
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
