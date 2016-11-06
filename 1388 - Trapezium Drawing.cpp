#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<cstring>
#include<climits>
#include<ctime>

#include<iostream>
#include<iomanip>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<sstream>
#include<bitset>
#include<algorithm>
using namespace std;

#define MAX 1000
#define PI acos(-1.0)
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<double , double> pdd;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef map<string, int> msi;
#define REP(i, b, e)\
    for(int i = int(b); i <= int(e); i++)
#define TRvi(c, it)\
    for(vi::iterator it = (c).begin(); it != (c).end(); ++it )
#define TRvii(c, it)\
    for(vii::iterator it = (c).begin(); it != (c).end(); ++it )
#define sf scanf
#define pf printf
#define si(x) sf("%d",&x)
#define in(x) cin>>x
#define out(x) cout<<(x)
#define x first
#define y second
#define ln length()
#define sz size()
#define clr clear()
#define pb push_back
#define mp make_pair
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a * (b / gcd(a,b)))
//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};
//int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
double dist(pii a,pii b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
pdd solve(pii p1,pii p2,double a,double b,double c,double d,int temp)
{
    double alpha=acos((-c*c+a*a+b*b)/(2*a*b));
    if(temp==2)alpha=-alpha;
    //printf("%lf ",alpha*180/PI);
    pii t=mp((p2.x-p1.x),(p2.y-p1.y));
    double por=a/d;
   // printf("%lf\n",por);
    pdd tp=mp(por*t.x,por*t.y);
    // printf("%lf %lf\n",tp.x,tp.y);
    pdd r;
    r.x=tp.x*cos(alpha)-tp.y*sin(alpha)+p1.x;
    r.y=tp.x*sin(alpha)+tp.y*cos(alpha)+p1.y;
    return r;
}
int main()
{
//    READ("in.txt");
//    double cl = clock();
     int b,c,d,T;
     pii p1,p2;
     double a,e;
     scanf("%d",&T);
     REP(t,1,T)
     {
         scanf("%d%d%d%d%d%d%d",&p1.x,&p1.y,&p2.x,&p2.y,&b,&c,&d);
         a=dist(p1,p2);
         e=a-c;
         pdd p3=solve(p1,p2,d*1.,e*1.,b*1.,a,1);
         pdd p4=solve(p2,p1,b*1.,e*1.,d*1.,a,2);
         printf("Case %d:\n",t);
         printf("%.10lf %.10lf ",p4.x,p4.y);
         printf("%.10lf %.10lf\n",p3.x,p3.y);
     }
//    cl = clock() - cl;
//    pf("Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);
    return 0;
}
