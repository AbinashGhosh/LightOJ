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
#define MOD 1000000007
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
// scanf("%d",&n);
pii a[100005];
int tree[100005];
bool cmp(pii c,pii d)
{
    return (c.x==d.x)? (c.y>d.y):(c.x<d.x);
}
int query(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum=(sum+tree[idx])%MOD;
        idx-=idx&(-idx);
    }
    return sum%MOD;
}
void update(int idx,int x,int n)
{
    while(idx<=n)
    {
        tree[idx]=(tree[idx]+ x)%MOD;
        idx+=idx&(-idx);
    }
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T,n,b;
    scanf("%d",&T);
    FOR(t,1,T)
    {
        scanf("%d",&n);
        FOR(i,1,n){
            scanf("%d",&b);
            a[i]={b,i};
        }
        sort(a+1,a+n+1,cmp);
        mem(tree,0);
        FOR(i,1,n)
        {
            int pos=a[i].y;
            update(pos,1+query(pos-1),n);
        }
        printf("Case %d: %d\n",t,query(n));
    }
	return 0;
}



