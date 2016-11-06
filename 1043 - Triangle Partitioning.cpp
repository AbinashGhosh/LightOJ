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
#define EPS 1e-7
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
    double a,b,c,r;
    scanf("%d",&t);
    FOR(i,1,t)
    {
        scanf("%lf%lf%lf%lf",&a,&b,&c,&r);
        double  de=sqrt(r/(r+1))*c;
        double  ad=(a*de)/c;
        printf("Case %d: %.9lf\n",i,ad);
    }
    return 0;
}

//Second  Solution Using Binary Search

//int main()
//{
//    int t;
//    double a,b,c,r,ar,s,ad;
//    scanf("%d",&t);
//    FOR(i,1,t)
//    {
//        scanf("%lf%lf%lf%lf",&a,&b,&c,&r);
//        double beg=EPS,end=a,mid;
//        s=(a+b+c)/2;
//        ar=sqrt(s*(s-a)*(s-b)*(s-c));
//        while(beg<=end)
//        {
//            ad=(beg+end)/2;
//            double de=(ad*c)/a;
//            double ae=(ad*b)/a;
//            double st=(ad+de+ae)/2;
//            double nar=sqrt(st*(st-ad)*(st-de)*(st-ae));
//            double nr=nar/(ar-nar);
//            if(nr<r)
//                beg=ad+EPS;
//            else
//                end=ad-EPS;
//        }
//        printf("Case %d: %.9lf\n",i,ad);
//    }
//    return 0;
//}
