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
int dp[51][51][51];
    char s[5][55];
int lcs(int p,int q,int r)
{
    if(p<0||q<0||r<0)return 0;
    if(dp[p][q][r]!=-1)return dp[p][q][r];
    if(s[1][p]==s[2][q]&&s[3][r]==s[2][q])return dp[p][q][r]=1+lcs(p-1,q-1,r-1);
    else return dp[p][q][r] =max(max(lcs(p-1,q,r),lcs(p,q-1,r)),lcs(p,q,r-1));
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T;

    int l[5];
    scanf("%d",&T);
    FOR(t,1,T)
    {
        //getchar();
        FOR(i,1,3){
        scanf("%s",s[i]);
        l[i]=strlen(s[i]);
        }
        mem(dp,-1);
        int  ans=lcs(l[1]-1,l[2]-1,l[3]-1);
        printf("Case %d: %d\n",t,ans);
    }

    return 0;
}

/*
3

abcdef
cdef
dcdef

aaaa
bbbb
ccca

aaaa
aaaa
aaa
*/
