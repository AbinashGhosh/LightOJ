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

char s1[34],s2[34];
ll dp[34][34][34];
int l1,l2,s[34][34];
int LCS()
{
    FOR(i,0,l1)
    {
        FOR(j,0,l2)
        {
            if(i==0||j==0){s[i][j]=0;continue;}
            if(s1[i-1]==s2[j-1])s[i][j]=s[i-1][j-1]+1;
            else s[i][j]=max(s[i-1][j],s[i][j-1]);
        }
    }
    return s[l1][l2];
}
ll solve(int a,int b,int l)
{

       //printf("%d ",a); pr2(b,l);
    if(l==0)
    {
        //pr2(a,b);
        if( a==0&&b==0)return 1;
        else return 0;
    }
    if(dp[a][b][l]!=-1)return dp[a][b][l];
    if(a==0)return dp[a][b][l]=solve(a,b-1,l-1);
    if(b==0)return dp[a][b][l]=solve(a-1,b,l-1);
    if(s1[a-1]==s2[b-1])dp[a][b][l]=solve(a-1,b-1,l-1);
    else dp[a][b][l]=solve(a,b-1,l-1) +solve(a-1,b,l-1);
   // pr( dp[a][b][l]);
    return dp[a][b][l];
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T;
    scanf("%d",&T);
    FOR(t,1,T)
    {
        //getchar();
        scanf("%s%s",s1,s2);
        //pr2(s1,s2);
        l1=strlen(s1);
        l2=strlen(s2);
        int ans=l1+l2-LCS();
        //pr(ans);
        mem(dp,-1);
        ll ans1=solve(l1,l2,ans);
       // pr(ans1);
       printf("Case %d: %d %lld\n",t,ans,ans1);
    }
    return 0;
}
/*
3
USA
USSR
LAILI
MAJNU
SHAHJAHAN
MOMTAJ
*/

