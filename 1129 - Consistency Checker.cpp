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
bool ans;
struct node{
    bool endmark;
    node *next[11];
    int cnt;
    node()
    {
        endmark=false;
        FOR(i,0,10)next[i]=NULL;
    }
}*root;
void Insert(char *str,int n)
{
    node *curr=root;
    bool create=true,before=false;
    FOR(i,0,n-1)
    {
        int id=str[i]-'0';
        if(curr->next[id]==NULL)
        {
            curr->next[id]=new node();
            create=false;
        }
        curr=curr->next[id];

        if(curr->endmark)
        {
            before=true;
            break;
        }
    }
    if(create||before)ans=false;
    curr->endmark=true;
}
void del(node *curr)
{
    FOR(i,0,10)
       if(curr->next[i])
          del(curr->next[i]);
    delete(curr);
}
int main()
{
    int T,n;
    char s[11];
    scanf("%d",&T);
    FOR(t,1,T)
    {
        root=new node();
        scanf("%d",&n);
        bool res=true;
        FOR(i,1,n)
        {
            scanf("%s",s);
            ans=true;
            if(!res)continue;
            Insert(s,strlen(s));
            res=ans&&res;
        }
        if(res)printf("Case %d: YES\n",t);
        else printf("Case %d: NO\n",t);
        del(root);
    }
	return 0;
}
/*
2
3
911
97625999
91125426
5
113
12340
123440
12345
98346
*/

