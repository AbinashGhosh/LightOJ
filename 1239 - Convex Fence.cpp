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
#define EPS 1e-11
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
typedef  vector <pii> vpii;
typedef  vector <ll > vl;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};
//int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

pii p0,pnt[50005],res[50005];
inline ll sqDistance(pii a,pii b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
inline ll cross(pii a, pii b, pii c)
{
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
inline bool comp(pii a,pii b)
{
    ll d=cross(p0,a,b);
    if(d<0||(!d&&sqDistance(p0,a)>sqDistance(p0,b)))return false;
    return true;
}

void convexHull(int np,int &nc)
{
   /// Remove duplicate points if necesary
    int pos=0;
    FOR(i,0,np-1)
       if(pnt[i].y<pnt[pos].y||(pnt[i].y==pnt[pos].y&&pnt[i].x<pnt[pos].x))
           pos=i;
    swap(pnt[0],pnt[pos]);
    p0=pnt[0];
    sort(pnt+1,pnt+np,comp);
    nc=min(np,3);
    FOR(i,0,nc-1){res[i]=pnt[i];}
    if(nc<3)return;
    int j=3;
    FOR(i,3,np-1)
    {
        while(cross(res[j-2],res[j-1],pnt[i])<0)j--;
        res[j++]=pnt[i];
    }
    nc=j;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T,d;
    int point,Bpoint;
    scanf("%d",&T);
    FOR(t,1,T)
    {

        scanf("%d%d",&point,&d);
        FOR(i,0,point-1)
        scanf("%lld %lld",&pnt[i].x,&pnt[i].y);
        convexHull(point,Bpoint);
        //pr(Bpoint);
        double ans=0.0;
        FOR(i,0,Bpoint-1)
        {
            ans+=sqrt(sqDistance(res[i],res[(i+1)%Bpoint]));

        }
        ans+=2*PI*d;
        printf("Case %d: %.10lf\n",t,ans+EPS);
    }
    return 0;
}


