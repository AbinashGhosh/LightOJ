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
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int t;
    double r1,r2,r3,a,b,c,x,y,z,A,s;
    scanf("%d",&t);
    FOR(i,1,t)
    {
        scanf("%lf%lf%lf",&r1,&r2,&r3);
        a=r1+r3;
        b=r1+r2;
        c=r3+r2;
        s=(a+b+c)/2.0;
        A=sqrt(s*(s-a)*(s-b)*(s-c));
        x=(acos((a*a+b*b-c*c)/(2*a*b))*r1*r1)/2.0;
        y=(acos((a*a-b*b+c*c)/(2*a*c))*r3*r3)/2.0;
        z=(acos((-a*a+b*b+c*c)/(2*c*b))*r2*r2)/2.0;
        double ans=A-x-y-z;
        printf("Case %d: %.10lf\n",i,ans);
    }
    return 0;
}

