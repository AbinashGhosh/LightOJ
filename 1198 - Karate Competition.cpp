#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>

#include <iostream>
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

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1, 0, 1};
//int dy[]={0,1,1, 1, 0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1, 1, 2};
//int dy[]={1,2, 2, 1,-1,-2,-2,-1};//Knight Direction
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T,n,a[200],b[200],v[200];
    scanf("%d",&T);
    FOR(t,1,T)
    {
        int count=0,carry=0,j;
        scanf("%d",&n);
        mem(v,0);
        FOR(i,0,n-1)
            scanf("%d",&a[i]);
        FOR(i,0,n-1)
            scanf("%d",&b[i]);
        sort(a,a+n);
        sort(b,b+n);
        FOR(j,0,n-1)
        {
            for(int i=n-1;i>=0;i--)
            {
                if(b[i]<a[j]&&b[i]!=0)
                {
                    a[j]=0;
                    b[i]=0;
                    count+=2;
                    break;
                }
            }
        }
        FOR(j,0,n-1)
        {
            for(int i=n-1;i>=0;i--)
            {
                if(b[i]==a[j]&&b[i]!=0)
                {
                    a[j]=0;
                    b[i]=0;
                    count+=1;
                    break;
                }
            }
        }
        printf("Case %d: %d\n",t,count);
    }
    return 0;
}

