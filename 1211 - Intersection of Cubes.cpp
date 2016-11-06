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

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T,n,a,b,c,a1,b1,c1,a2,b2,c2;
    scanf("%d",&T);
    FOR(t,1,T)
    {
        scanf("%d",&n);
        a1=0,b1=0,c1=0,a2=1000000001,b2=1000000001,c2=1000000001;
        FOR(i,1,n)
        {
            scanf("%d%d%d",&a,&b,&c);
            a1=max(a1,a);
            b1=max(b1,b);
            c1=max(c1,c);
            scanf("%d%d%d",&a,&b,&c);
            a2=min(a2,a);
            b2=min(b2,b);
            c2=min(c2,c);
        }
        int ans=(a2-a1)*(b2-b1)*(c2-c1);
        if(ans<0)ans=0;
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}

