//Abinash Ghosh
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
int a[40],lim,pos,n,k;
vl v[2];
void part(int i,ll sum)
{
    if(sum>k)return;
    if(i>lim)
    {
        v[pos].pb(sum);
        return ;
    }
    part(i+1,sum);
    part(i+1,sum+a[i]);
}
int main()
{
    //READ("in.in");
    //WRITE("out.out");
    int T;
    scanf("%d",&T);
    FOR(t,1,T)
    {
        scanf("%d%d",&n,&k);
        FOR(i,0,n-1)
        scanf("%d",&a[i]);
        lim=n/2,pos=0;
        part(0,0ll);
        lim=n-1,pos=1;
        part(n/2+1,0ll);
        Sort(v[0]);
        Sort(v[1]);
        int ans=0;
        FOR(i,0,(int)v[0].size()-1)
        {
            int val=upper_bound(v[1].begin(),v[1].end(),k-v[0][i])-v[1].begin();
            ans+=(val);
        }
        v[0].clear();
        v[1].clear();
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}















