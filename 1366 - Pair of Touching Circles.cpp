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
#define MAX 10000007
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
int d[505],e[505],f[505],s;
ll pre()
{
    s=0;
    FOR(i,1,505)
    {
        FOR(j,i+1,505)
        {
            int k=(int)(sqrt(j*j+i*i)+0.5);
            if(k*k==(j*j+i*i))
            {
                d[s]=i;
                e[s]=j;
                f[s++]=k;
            }
        }
    }
    return s-1;
}
ll solve(int l,int w)
{
    ll ans=0;
    int mx=min(l,w);
    for(int i=2; i<=mx; i=i+2)
    {
        for(int j=2; j<=mx; j=j+2)
        {
            int mxx=max(i,j);
            if(!(l<i+j||w<mxx))
            ans+=(l-(i+j)+1)*(w-mxx+1);
            if(!(w<i+j||l<mxx))
            ans+=(w-(i+j)+1)*(l-mxx+1);
           // pr(ans);
        }
    }
    return ans;
}
ll solve2(int H,int w)
{
    ll ans=0;
    int i,j,k;
    FOR(g,0,s-1)
    {
        i=d[g],j=e[g],k=f[g];
        FOR(l,1,k-1)
        {
            int h=max(2*max(l,k-l),k+i);
            int p=max(2*max(l,k-l),k+j);
            ll temp=0;
            if(h<=H&&p<=w)
                temp+=(H-h+1)*(w-p+1);
            if(h<=w&&p<=H)
                temp+=(H-p+1)*(w-h+1);
            ans+=2*temp;
            //pr(ans);
        }
    }
    return ans;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T,l,w;
    pre();
    scanf("%d",&T);
    FOR(t,1,T)
    {
        scanf("%d%d",&l,&w);
        ll ans=solve(l,w)+solve2(l,w);
        printf("Case %d: %lld\n",t,ans);
    }
    return 0;
}

