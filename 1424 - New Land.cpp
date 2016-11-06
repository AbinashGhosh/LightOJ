//Abinash Ghosh
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
#include <ctime>
#include <cassert>
using  namespace  std;

#define PI acos(-1.0)
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define Sort(x) sort(x.begin(),x.end())
#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORR(i, b, e) for(int i = b; i >= e; i--)
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

#define MAX 10000007
#define EPS 1e-9
const int MX = 2005 ;
int height[MX][MX] ;
char str[MX][MX];
int n , m , lft[MX] ;
void solve()
{
    int cs , t  ;
    scanf("%d",&t);
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        scanf("%d",&n);
        scanf("%d",&m);
        FOR(i,0,n-1)
            scanf("%s",str[i]);
        FOR(j,0,m-1)
            if( str[0][j] == '1' )height[0][j] = 0 ;
            else height[0][j] = 1 ;
        FOR(i,1,n-1)
            FOR(j,0,m-1)
                if( str[i][j] == '1' ) height[i][j] = 0 ;
                else height[i][j] = height[i-1][j] + 1 ;
        int  ans = 0 ;
        stack < int > s ;
        int j , r;
        FOR(j,0,n-1)
        {
            int tp,area_with_top,i = 0;
            while (i < m||!s.empty())
            {
                if (i<m&&(s.empty() || height[j][s.top()] <= height[j][i]))
                    s.push(i++);
                else
                {
                    tp = s.top();
                    s.pop();
                    area_with_top = height[j][tp] * (s.empty() ? i : i - s.top() - 1);
                    ans=max(ans,area_with_top);
                }
            }
//            int top = 1, i;
//            height[j][0] = st[0] = height[j][m+1] = 0;
//            for(i = 1; i <= m+1; i++)
//            {
//                while(top > 1 && height[j][st[top-1]] >= height[j][i])
//                {
//                    ans = max(ans, height[j][st[top-1]]*(i - st[top-2]-1));
//                    top--;
//                }
//                st[top++] = i;
//            }

        }
        printf("Case %d: %d\n",cs,ans);
    }
}
int main()
{
    //READ("in.in");
    // WRITE("out.out");
    solve();
    return 0;
}



