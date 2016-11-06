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
int ans=0;
char DNA[5]="ACGT";
struct node
{
    bool endmark;
    int cnt;
    node *next[4];
    node()
    {
        endmark=false;
        cnt=0;
        FOR(i,0,3)next[i]=NULL;
    }
}*root;
int fun(char c)
{
    FOR(i,0,3)if(c==DNA[i])return i;
    return 0;
}
void Insert(char *str,int n)
{
    node *curr=root;
    int id;
    FOR(i,0,n-1)
    {
         id=fun(str[i]);
         if(curr->next[id]==NULL)
            curr->next[id]=new node();
         curr=curr->next[id];
         curr->cnt++;
         ans=max(curr->cnt*(i+1),ans);
    }
    curr->endmark=true;
}
void del(node *curr)
{
    FOR(i,0,3)
       if(curr->next[i])
        del(curr->next[i]);
    delete (curr);
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    char s[52];
    int T,n;
    scanf("%d",&T);
    FOR(t,1,T)
    {
        ans=0;
        root=new node();
        scanf("%d",&n);
        FOR(i,1,n)
        {
            scanf("%s",s);
            Insert(s,strlen(s));
        }
        printf("Case %d: %d\n",t,ans);
        del(root);
    }

	return 0;
}
/*
3
4
ACGT
ACGTGCGT
ACCGTGC
ACGCCGT
3
CGCGCGCGCGCGCCCCGCCCGCGC
CGCGCGCGCGCGCCCCGCCCGCAC
CGCGCGCGCGCGCCCCGCCCGCTC
2
CGCGCCGCGCGCGCGCGCGC
GGCGCCGCGCGCGCGCGCTC
*/


