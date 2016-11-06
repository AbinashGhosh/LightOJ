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

/*
Split the d area into two triangles. One formed by FEX (we'll call its area p), and one formed by FEA
(let's call its area q).Now, to find the area of p, you can rely on the following information:
    The triangle BFX has area a. Let's say that its base is BX, and its height is h1.
    Then the base of FXE can be XE, and its height is also h1.
    Similarly, the triangle BXC can be said to have base BX and height h2.
    And the triangle XEC has base XE and height h2.
    So 0.5*XE*h1=p, 0.5*BX*h1=a, so XE/BX=p/a
       0.5*XE*h2=c, 0.5*BX*h2=b, so XE/BX=b/c
Knowing all these relations, you can deduce that p = a*c/b.
For the value of q, there are many ways to get it. Use a similar reasoning,
and triangles like AFE, AFC, BFE and BFC to deduce q.

*/


int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int t=1;
    double a,b,c,p,q,tmp;
    while(1)
    {
        scanf("%lf%lf%lf",&a,&b,&c);
        if(a==-1) break;
        p=(a*c)/b;
        tmp=(b-p);
        if(fabs(tmp)<EPS||b==0.0)
        printf("Set %d:\nPoor King!\n",t++);
        else
        {
            q=(a*c+a*p+p*c+p*p)/tmp;
            if(p+q>0)
            printf("Set %d:\n%.4lf\n",t++,p+q);
            else
            printf("Set %d:\nPoor King!\n",t++);
        }
    }
    return 0;
}
