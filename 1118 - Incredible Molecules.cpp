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
#define WRITE(f) freopen(f, "r", stdout)

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
inline double dist(pdd a,pdd b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int t;
    pdd c1,c2;
    double r1,r2,ans;
    scanf("%d",&t);
    FOR(i,1,t)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&c1.x,&c1.y,&r1,&c2.x,&c2.y,&r2);
        double d=dist(c1,c2);
        //where two circle don't met
        if(d>=r1+r2)
        {
            printf("Case %d: 0\n",i);
            continue;
        }
        //where one circle contain another
        if(d+r1<=r2||d+r2<=r1)
        {
            double ans=PI*min(r1,r2)*min(r1,r2);
            printf("Case %d: %.10lf\n",i,ans);
            continue;
        }
        double a1=2*acos((d*d+r1*r1-r2*r2)/(2*r1*d));
        double a2=2*acos((d*d+r2*r2-r1*r1)/(2*r2*d));
        double s1=(r1*r1*a1)/2;
        double s2=(r2*r2*a2)/2;
        //=((r1*sin(a1/2)*2)*(r1*cos(a1/2)))/2
        //=(r1*r1*2*sin(a/2)*cos(a/2))/2
        //=(r1*r1*sin(a1))/2
        // same as A2
        double A1=(r1*r1*sin(a1))/2;
        double A2=(r2*r2*sin(a2))/2;
        ans=(s1-A1)+(s2-A2);
        printf("Case %d: %.10lf\n",i,ans);

    }
    return 0;
}
/*
2
0 0 1 10 10 1
0 0 10 0 0 5
*/
