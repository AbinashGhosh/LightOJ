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

char s[105],r[105];
int dp[105][105];
int l;
int LCS(int i,int j)
{
    //pr2(i,j);    printf("%s %s00\n",s,r);
    if(i<0||i>=l||j<0||j>=l)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ret=0;

    if(s[i]==r[j])
        ret=1+LCS(i+1,j+1);
    else
        ret=max(LCS(i,j+1),LCS(i+1,j));
    return dp[i][j]=ret;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T;
    scanf("%d\n",&T);
    FOR(t,1,T)
    {
        mem(dp,-1);
        gets(s);
        l=strlen(s);
        int j=l-1;
        r[l]='\0';
        FOR(i,0,l-1)
        r[j--]=s[i];
        //printf("%s %s\n",s,r);
        int ans =l-LCS(0,0);
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
/*
6
abcd
aaaa
abc
aab
abababaabababa
pqrsabcdpqrs
*/
