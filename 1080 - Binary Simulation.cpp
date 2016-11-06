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
char s[100005];
int  a[100005];
int tree[100005],l;
int query(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=idx&(-idx);
    }
    return  sum;
}
void update(int idx,int x)
{
    while(idx<=l)
    {
        tree[idx]+=x;
        idx+=idx&(-idx);
    }
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T,q,c,d,x;

    scanf("%d",&T);
    FOR(t,1,T)
    {
        printf("Case %d:\n",t);
        scanf("%s",s+1);
        mem(tree,0);
        l=strlen(s+1);
        FOR(i,1,l)
        {
            if(s[i]=='0')a[i]=0;
            else a[i]=1;
        }
        //pr(s+1);
        scanf("%d",&q);
        //pr(q);

        char ch;
        FOR(i,1,q)
        {
            getchar();
            scanf("%c",&ch);
            if(ch=='I')
            {
                scanf("%d %d",&c,&d);
                update(d+1,-1);
                update(c,1);

//                FOR(k,1,l)
//                {
//                    int ans=query(k);
//                if(k!=1)ans-=query(k-1);
//                printf("%d ",ans);
//                }
            }
            else
            {
                scanf("%d",&x);
                int ans=query(x);
                printf("%d\n",a[x]^(ans%2));
            }
        }
    }
	return 0;
}
/*
2
0011001100
6
I 1 10
I 2 7
Q 2
Q 1
Q 7
Q 5
1011110111
6
I 1 10
I 2 7
Q 2
Q 1
Q 7
Q 5
*/
