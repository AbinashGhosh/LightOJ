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
#define mxx 52
int getid(char ch)
{
    if(ch>='A' && ch<='Z') return ch-'A';
    return ch-'a'+26;
}
struct node{
    int endmark;
    node *next[53];
    node()
    {
        endmark=false;
        FOR(i,0,52)next[i]=NULL;
    }
}*root;
void Insert(char *str,int n)
{
    node *curr=root;
    FOR(i,0,n-1)
    {
        int id=getid(str[i]);
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
    }
    curr->endmark++;
}
int  Search(char *str,int n)
{
    node *curr=root;
    FOR(i,0,n-1)
    {
        int id=getid(str[i]);
        if(curr->next[id]==NULL)return false;
        curr=curr->next[id];
    }
    return curr->endmark;
}
void del(node *curr)
{
    FOR(i,0,52)
       if(curr->next[i])
          del(curr->next[i]);
    delete(curr);
}
int main()
{
    int T,n;
    char s[10005];
    scanf("%d",&T);
    FOR(t,1,T)
    {
        root=new node();
        scanf("%d",&n);
        FOR(i,1,n)
        {
            scanf("%s",s);
            int len= strlen(s);
            if(len>2)
            sort(s+1,s+len-1);
            Insert(s,strlen(s));
        }
        printf("Case %d:\n",t);
        int mm;
        scanf("%d ",&mm);
        FOR(i,1,mm)
        {
        gets(s);
        //stringstream ss(s);
        int ans=1;
        char *ptr=strtok(s," ");
        while(ptr)
        {
            int len= strlen(ptr);
            if(len>2)
            sort(ptr+1,ptr+len-1);
            ans*=Search(ptr,strlen(ptr));
            if(ans==0)break;
            ptr=strtok(NULL," ");
        }
        printf("%d\n",ans);
        }
        del(root);
    }

	return 0;
}
/*
1
8
baggers
beggars
in
the
blowed
bowled
barn
bran
1
beggars bowled in the barn
*/

