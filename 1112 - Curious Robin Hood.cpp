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
int arr[MAX],tree[MAX*3];
void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
int query(int node,int b,int e,int i,int j)
{
    if(i>e||j<b)return 0;
    if(b>=i&&e<=j)return tree[node];
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return p1+p2;
}
void update(int node,int b,int e,int i,int newv,bool chk)
{
    if(i>e||i<b)return;
    if(b>=i&&e<=i)
    {
        tree[node]+=newv;
        if(chk)tree[node]=newv;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,newv,chk);
    update(right,mid+1,e,i,newv,chk);
    tree[node]=tree[left]+tree[right];
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T,n,q,a,b,qt;
    scanf("%d\n",&T);
    FOR(t,1,T)
    {
        scanf("%d%d",&n,&q);
        FOR(i,1,n)scanf("%d",&arr[i]);
        init(1,1,n);
        printf("Case %d:\n",t);
        FOR(i,1,q)
        {
            scanf("%d",&qt);
            if(qt==1)
            {
                scanf("%d",&a);
                printf("%d\n",query(1,1,n,a+1,a+1));
                update(1,1,n,a+1,0,true);
            }
            else if(qt==2)
            {
                scanf("%d%d",&a,&b);
                update(1,1,n,a+1,b,false);
            }
            else
            {
                scanf("%d%d",&a,&b);
                printf("%d\n",query(1,1,n,a+1,b+1));
            }
        }
    }
    return 0;
}

