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
int a[1005];
bool possible(int n,int v,int k)
{
    int sum=0,ans=0;
    FOR(i,1,n)
    {
        sum+=a[i];
        if(sum>v)
        {
            ans++;
            sum=a[i];
        }
    }
    return ans<=k;
}
int main()
{
    // READ("in.in");
    //WRITE("out.out");
    int T,n,k;
    scanf("%d",&T);
    FOR(cs,1,T)
    {
        scanf("%d%d",&n,&k);
        int mx=0,sum=0;
        FOR(i,1,n)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
            mx=max(mx,a[i]);
        }
        k--;
        int lo=mx,hi=sum,mid,best=-1;
        while(lo<=hi)
        {
            mid=(hi+lo)/2;
            if(possible(n,mid,k))
            {
                best=mid;
                hi=mid-1;
            }
            else
                lo=mid+1;
        }
        printf("Case %d: %d\n",cs,best);
    }
    return 0;
}





