
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

#define MAX 1000007
#define EPS 1e-9

bool mark[10005];
int prime[10005];
int fac[10001][103];
int  prime_gen(int n)
{
    for(int i=3;i*i<=n;i+=2)
        if(!mark[i])
            for(int j=i*i,k=i<<1;j<=n;j+=k)
            mark[j]=true;
    int k=0;
    prime[k++]=2;
    for(int i=3;i<=n;i+=2)if(!mark[i])prime[k++]=i;
    return k;
}
void coutdivisor(int n,int k)
{
    int x=n;
    for(int i=0;i<k&&prime[i]*prime[i]<=n;i++)
    {
        if(n%prime[i]==0)
        {
            int cnt=0;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                cnt++;
            }
            fac[x][prime[i]]=cnt;
        }
    }
    if(n>1)
    {
        if(n>100)fac[x][102]=n;
        else fac[x][n]=1;
    }
}
string multiply( string a, int b )
{
    // a contains the biginteger in reversed form
    int carry = 0;
    for( int i = 0; i < a.size(); i++ )
    {
        carry += (a[i] - 48) * b;
        a[i] = ( carry % 10 + 48 );
        carry /= 10;
    }
    while( carry )
    {
        a += ( carry % 10 + 48 );
        carry /= 10;
    }
    return a;
}
int ans[10004];
int main()
{
    //READ("in.in");
    //WRITE("out.out");
    int  T,a,b,c,d,n,cnt;
    cnt=prime_gen(10007);
    FOR(i,1,10000)
    coutdivisor(i,cnt);
    //FOR(i,1,102)pr2(i,fac[10000][i]);
    scanf("%d",&T);
    FOR(cs,1,T)
    {
        mem(ans,0);
        scanf("%d",&n);
        FOR(j,1,n)
        {
            scanf("%d",&b);
            FOR(i,1,102)
            {
                if(i==102)
                ans[fac[b][i]]=max(ans[fac[b][i]],1);
                else
                ans[i]=max(ans[i],fac[b][i]);
            }
        }
        string res="1";
        FOR(i,1,10000)
        {
            if(ans[i]>0)
            FOR(j,1,ans[i])res=multiply(res,i);
        }
        reverse(res.begin(),res.end());
        printf("Case %d: %s\n",cs,res.c_str());
    }
    return 0;
}

// 16641680829583789980
// 8320840414791894990000




