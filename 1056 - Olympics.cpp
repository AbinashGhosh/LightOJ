
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
double l,w;
pdd cfsol()
{
        double r=sqrt((l*l)/4+(w*w)/4);  // r^2=(l/2)^2 + (w/2)^2
        double alpha=acos((1-((w*w)/(2*r*r)))); // from (r,r,w) triangle sector anngle
        double arc=(alpha*r); // then sector arc
        double peri=400.0/(2*l+2*arc); // ratio of perimeter
        return pdd( l*peri,w*peri);
}
double cal(double len)
{
    double wid=((w*len)/l); // width from the ratio
    double r=sqrt(wid*wid+len*len )/2.; // r of rectangle inscribed in a circle
    double angle=acos((r*r+r*r-wid*wid)/(2.*r*r)); // sectors angle
    double s=r*angle; // arc of the angle
    double tot=2.*s+2.*len; // total length of the track
    return tot;
}
pdd bssol()
{
    double hi=200.0, lo=EPS,mid;
    for(int i=1;i<=200;i++)
    {
        mid=(lo+hi)/2.;
        if(cal(mid)<400.0)
            lo=mid;
        else hi=mid;

    }
    return pdd( lo,((w*lo)/l) );
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T;

    scanf("%d",&T);
    FOR(t,1,T)
    {
        scanf("%lf%*c%*c%*c%lf",&l,&w);
        pdd ans=bssol();

        printf("Case %d: %.10lf %.10lf\n",t,ans.x,ans.y);
    }
    return 0;
}

