#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>

#include <iostream>
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

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1, 0, 1};
//int dy[]={0,1,1, 1, 0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1, 1, 2};
//int dy[]={1,2, 2, 1,-1,-2,-2,-1};//Knight Direction
ll adjcount[35],powof2[35];
ll solve(ll n)
{
    if(n<2)return 0;
    int k=log2(n+1);
    ll remain=n-powof2[k]+1;
    ll ans=adjcount[k-1]+max(remain-powof2[k-1],(ll)0)+solve(remain-1);
    //pr(ans);
    return ans;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    adjcount[0]=0;
    powof2[0]=1;
    FOR(i,1,31)
    {
        adjcount[i]=2*adjcount[i-1]+powof2[i-1];//Count the adjcent 1 from 0 to 2^i
        powof2[i]=2*powof2[i-1];
        //pr(adjcount[i]);
    }
    ll T,n;
    scanf("%lld",&T);
    FOR(t,1,T)
    {
        scanf("%lld",&n);
        ll ans=solve(n);
        printf("Case %d: %lld\n",t,ans);
    }
    return 0;
}

