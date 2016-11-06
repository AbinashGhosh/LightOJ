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

struct point
{
    double x,y,z;
    point(){};
    point(double xx,double yy,double zz)
    {
        x=xx,y=yy,z=zz;
    }
};
point p,q,r;
double dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}
double ternaryS()
{
    point d;
    d.x=-(p.x-q.x);
    d.y=-(p.y-q.y);
    d.z=-(p.z-q.z);
    double l=0.0,h=1.0,m1,m2,res=100000000;
    FOR(i,1,200)
    {
        m1=l+(h-l)/3.0;
        m2=h-(h-l)/3.0;
        //pr2(m1,m2);
        //pr2(m1,m2);
        point e(p.x+d.x*m1,p.y+d.y*m1,p.z+d.z*m1);
        point f(p.x+d.x*m2,p.y+d.y*m2,p.z+d.z*m2);
        if(dist(e,r)<dist(f,r))
            h=m2;
        else l=m1;
        res=min(res,dist(e,r));
        res=min(res,dist(f,r));
        //pr2(dist(e,r),dist(f,r));
    }
    return res;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T;
    scanf("%d",&T);
    FOR(t,1,T)
    {
        scanf("%lf%lf%lf",&p.x,&p.y,&p.z);
        scanf("%lf%lf%lf",&q.x,&q.y,&q.z);
        scanf("%lf%lf%lf",&r.x,&r.y,&r.z);
        double ans=ternaryS();
        printf("Case %d: %.10lf\n",t,ans);
    }
    return 0;
}
