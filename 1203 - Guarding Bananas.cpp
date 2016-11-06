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
//typedef  pair <int, int> pii;
typedef  pair <double , double> pdd;
typedef  pair <ll , ll > pii;
typedef  vector <int> vi;
//typedef  vector <pii> vpii;
typedef  vector <ll > vl;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};
//int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
pii p[100005],p0,s[100005];
inline ll sqDistance(pii a,pii b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
inline int ccw(pii a,pii b,pii c)
{
    ll d=(b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
    if(d<0)return -1;//cw
    if(d>0)return 1;
    return 0;
}
bool cmp(pii  a,pii b)
{
    int d=ccw(p0,a,b);
    if(d<0||(!d&&sqDistance(p0,a)>sqDistance(p0,b)))return false;
    return true;
}
void makeunique(int &np)
{
    sort(p,p+np);
    np=unique(&p[0],&p[np])-p;
}
void convexHull(int np,int &nc)
{
    int pos=0;
    FOR(i,0,np-1)
        if(p[i].y<p[pos].y||(p[i].y==p[pos].y&&p[i].x<p[pos].x))
            pos=i;
    swap(p[0],p[pos]);
    p0=p[0];
    sort(&p[1],&p[np],cmp);
    int j=0;
    FOR(i,0,np-1)
    {
        //use <= to remove colinear points
        while(j>=2&&ccw(s[j-2],s[j-1],p[i])<=0)j--;
        s[j++]=p[i];
    }
    nc=j;
}
double angleBvector(pii o,pii a,pii b)
{
    pii c=mp(a.x-o.x,a.y-o.y);
    pii d=mp(b.x-o.x,b.y-o.y);
    double theta=atan2(d.y,d.x)-atan2(c.y,c.x);
    if(theta<0)theta+=2*PI;
    return theta;
}
int main()
{
    READ("1203 - Guarding Bananas.txt");
    //WRITE("out.txt");
    int T,np ,nc=0;
    scanf("%d",&T);
    FOR(t,1,T)
    {
        scanf("%d",&np);
        FOR(i,0,np-1)
        {
            scanf("%lld%lld",&p[i].x,&p[i].y);
        }
        makeunique(np);
        if(np>2)
        convexHull(np,nc);
        else
        {
           printf("Case %d: 0\n",t);continue;
        }
        double ans=100.0;
        //pr(nc);
        FOR(i,2,nc+1)
        {
            double temp=angleBvector(s[(i-1)%nc],s[i%nc],s[(i-2)%nc]);
            //pr(temp);
            ans=min(ans,temp);
        }
        if(ans==100.0)ans=0.0;
        //pr(ans);
        ans=ans*180/PI;
        printf("Case %d: %.10lf\n",t,ans);
    }
    return 0;
}


