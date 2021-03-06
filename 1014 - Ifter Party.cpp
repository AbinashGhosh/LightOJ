
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
vi ans;
int countDivisor(int n,int l)
{
    int div=0,b,sq=sqrt(n)+EPS;
    for(int i=1;i<=sq;++i)
        if(n%i==0)
        {
            if((i*i)==n){
                if(i>l)ans.pb(i);}
            else{
                b=n/i;
                if(b>l)ans.pb(b);
                if(i>l)ans.pb(i);
            }
        }
    return div;
}
int main()
{
    //READ("in.in");
    //WRITE("out.out");
    int T,p,l,q;
    scanf("%d",&T);
    FOR(cs,1,T)
    {
        scanf("%d%d",&p,&l);
        q=p-l;

        countDivisor(q,l);
        Sort(ans);
        printf("Case %d:",cs);
        FOR(i,0,(int)ans.size()-1)printf(" %d",ans[i]);
        if((int)ans.size()==0)printf(" impossible");
        printf("\n");
        ans.clear();
    }
    return 0;
}




