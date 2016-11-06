//Abinash Ghosh(Om)
// Linked List Implementation - not much memory efficient.
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
// scanf("%d",&n);
#define value(x) ((x)=='A'?0:(x)=='C'?1:(x)=='G'?2:(x)=='T'?3:4)
#define mxx 4
struct node{
    int next[mxx],val;
}tree[800000];
int last,ans;
void Insert(char *str)
{
    int curr=0;
    for(int i=0;str[i];i++)
    {
        int k=value(str[i]);
        if(tree[curr].next[k]==-1)
        {
           tree[curr].next[k]=++last;
           mem(tree[last].next,-1);
           tree[last].val=0;
        }
        curr=tree[curr].next[k];
        tree[curr].val++;
        ans=max(ans,tree[curr].val*(i+1));
    }
}
int Search(char *str)
{
    int curr=0;
    for(int i=0;str[i];i++)
    {
        int k=str[i]-'a';
        if(tree[curr].next[k]==-1)return 0;
        curr=tree[curr].next[k];
    }
    return tree[curr].val;
}
int main()
{
    int T,n;
    char s[52];
    scanf("%d",&T);
    FOR(t,1,T)
    {
        last=ans=0;
        mem(tree[0].next,-1);
        tree[0].val=0;
        scanf("%d",&n);
        FOR(i,1,n)
        {
            scanf("%s",s);
            Insert(s);
        }
        printf("Case %d: %d\n",t,ans);
    }
	return 0;
}
