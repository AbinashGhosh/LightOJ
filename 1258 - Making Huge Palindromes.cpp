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
using namespace std;

#define PI acos(-1.0)
#define MAX 10000007
#define EPS 1e-9
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define Sort(x) sort(x.begin(),x.end())
#define Reverse(x) reverse(x.begin(),x.end())
#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define pr(x) cout<<x<<"\n"
#define READ(f) freopen(f, "r", stdin)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double,double> pdd;
typedef pair<ll , ll > pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<ll > vl;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

void CPF(string P,int next[])
{
    int q=0,m=P.size();
    next[0]=0;
    for(int i=1;i<m;++i)
    {
        while(q>0&&P[i]!=P[q])
           q=next[q-1];
        if(P[i]==P[q])q++;
         next[i]=q;
    }

}
int KMPm(string T,string P)
{
    int q=0,m=P.size(),n=T.size();
    int next[m];
    CPF(P,next);
    for(int i=0;i<n;++i)
    {
        while(q>0&&T[i]!=P[q])
           q=next[q-1];
        if(T[i]==P[q])q++;
    }
    return q;
}
int main()
{
    //READ("in.txt");
    int t,cnt;
    string P,T;
    scanf("%d\n",&t);
    FOR(i,1,t)
    {
        cin>>T;
        P=T;reverse(P.begin(),P.end());
        cnt =2*P.size()-KMPm(T,P);
        printf("Case %d: %d\n",i,cnt);
    }
    return 0;
}




