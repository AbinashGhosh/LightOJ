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

#define PI 2.0*acos(0.0)
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
#define pr(x,y) cout<<x<<" "<<y<<"\n"
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
    int t,n;
    double R,r,k,a,b,c;
    scanf("%d",&t);
    FOR(i,1,t)
    {
        scanf("%lf%d",&R,&n);
//        k=1-cos((2*PI)/n);
//        a=k-2;
//        b=-2*R*k;
//        c=k*R*R;
//        r=(-b-sqrt(((b*b)-(4*a*c))))/(2*a)+EPS;
//        if(n==2)
//        r=R/2+EPS;
        k=360/n;
        a=sin((k*PI)/180)+2*sin((((180-k)/2)*PI)/180);
        r=R/a;
        printf("Case %d: %.10lf\n",i,r);
    }
    return 0;
}

