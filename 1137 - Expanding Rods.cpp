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
#define EPS 1e-10
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

double l,n,arc,C;
double bssol()
{
    arc=(1+n*C)*l;
    double hi=180.0,lo=0.0,m,ans;
    while(hi-lo>EPS)
    {
        m=(lo+hi)/2.0;
        //pr(m);
        ans=l*m*2.0*PI-360.0*arc*sqrt(2*(1-cos(m*PI/180.0)));
        if(ans>0)hi=m;
        else lo=m;
    }
    double r=sqrt(l*l/(2*(1-cos(m*PI/180))));
    ans=r-r*cos(m*PI/360);
    if(fabs(arc-l)<EPS)ans=0.0;
    return ans;
}
double bssol2()
{
    arc=(1+n*C)*l;
    double hi=l,lo=0.0,m,ans;
    FOR(i,1,200)
    {
        m=(lo+hi)/2.0;
        ans= m*(PI-2*acos(l/(2.*m)));
        pr(ans);
        if(ans<arc)hi=m;
        else lo=m;
    }
    ans=lo-sqrt(lo*lo-l*l/4);
    if(fabs(arc-l)<EPS)ans=0.0;
    return ans;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T;

    scanf("%d",&T);
    FOR(t,1,T)
    {
        scanf("%lf%lf%lf",&l,&n,&C);
        double ans=bssol2();
        printf("Case %d: %.10lf\n",t,ans);
    }
    return 0;
}


