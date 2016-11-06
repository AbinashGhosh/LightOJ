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
pii p[5];
double Distance(pdd a,pdd b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double ternaryS(pii a,pii b,pii c,pii d)
{
    pdd ha=b,la=a,hb=d,lb=c,m1l1,m1l2,m2l1,m2l2;
    FOR(i,1,500)
    {
        m1l1.x=la.x+(ha.x-la.x)/3;
        m1l1.y=la.y+(ha.y-la.y)/3;
        m2l1.x=ha.x-(ha.x-la.x)/3;
        m2l1.y=ha.y-(ha.y-la.y)/3;

        m1l2.x=lb.x+(hb.x-lb.x)/3;
        m1l2.y=lb.y+(hb.y-lb.y)/3;
        m2l2.x=hb.x-(hb.x-lb.x)/3;
        m2l2.y=hb.y-(hb.y-lb.y)/3;

        if(Distance(m1l1,m1l2)<Distance(m2l1,m2l2))
            ha=m2l1,hb=m2l2;
        else
            la=m1l1,lb=m1l2;
    }
    return Distance(la,lb);
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T;
    scanf("%d",&T);
    FOR(t,1,T)
    {
        FOR(i,0,3)
        scanf("%d%d",&p[i].x,&p[i].y);
        double ans=ternaryS(p[0],p[1],p[2],p[3]);
        printf("Case %d: %.11lf\n",t,ans);
    }
    return 0;
}

