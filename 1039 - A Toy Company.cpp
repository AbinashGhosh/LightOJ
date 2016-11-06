//OM
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <utility>
#include <sstream>
#include <algorithm>
using  namespace  std;

#define  x first
#define  y second
#define  pb push_back
#define  mp make_pair
#define  PI (acos(-1.0))
#define  mem(a,b) memset(a,b,sizeof(a))
#define  Sort(x) sort(x.begin(),x.end())
#define  FOR(i, b, e) for(int i = b; i <= (int)(e); i++)
#define  FORR(i, b, e) for(int i = b; i >=(int)(e); i--)
#define  FORI(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define  pr(x) cout<<x<<"\n"
#define  prs(x) cout<<x<<" "
#define  pr2(x,y) cout<<x<<" "<<y<<"\n"
#define  pr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define  ppr(a) cout<<a.x<<" "<<a.y<<"\n"

typedef  long long ll;
typedef  pair <int, int> pii;
typedef  pair <double , double> pdd;
typedef  vector <int> vi;
typedef  vector <pii> vpii;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

int dx[]={1,0,0,-1,0,0};
int dy[]={0,1,0,0,-1,0};
int dz[]={0,0,1,0,0,-1};

#define  EPS 1e-9
#define  MAX 100007

string a,b,c,ss,se;
int vis[26][26][26];

int BFS()
{
    char ts;
    queue<string>Q;
    Q.push(ss);
    if(vis[ss[0]-'a'][ss[1]-'a'][ss[2]-'a']==1)return -1;
    vis[ss[0]-'a'][ss[1]-'a'][ss[2]-'a']=0;
    while(!Q.empty())
    {
        string u=Q.front();
      //  pr(u);
        Q.pop();
        if(u==se)return vis[u[0]-'a'][u[1]-'a'][u[2]-'a'];
        FOR(i,0,5)
        {
            string gs;
            ts=(u[0]-'a'+dx[i]+26)%26+'a';gs+=ts;
            ts=(u[1]-'a'+dy[i]+26)%26+'a';gs+=ts;
            ts=(u[2]-'a'+dz[i]+26)%26+'a';gs+=ts;
           // pr(gs);
            if(vis[gs[0]-'a'][gs[1]-'a'][gs[2]-'a']==-1)
            {
                Q.push(gs);
                vis[gs[0]-'a'][gs[1]-'a'][gs[2]-'a']=vis[u[0]-'a'][u[1]-'a'][u[2]-'a']+1;
            }
        }
    }
    return -1;
}
int main()
{
    int T,n;
    scanf("%d",&T);
    FOR(cs,1,T)
    {
        getchar();
        getchar();
        cin>>ss>>se;
        scanf("%d",&n);
        mem(vis,-1);
        FOR(sr,1,n)
        {
            getchar();
            cin>>a>>b>>c;
            FOR(i,0,a.size()-1)
            FOR(j,0,b.size()-1)
            FOR(k,0,c.size()-1)
            vis[a[i]-'a'][b[j]-'a'][c[k]-'a']=1;
        }
        int ans=BFS();
        printf("Case %d: %d\n",cs,ans);
    }
    return 0;
}
/*
3

aab
zna
8
a a a
a a z
a z a
z a a
a z z
z a z
z z a
z z z

aaa
aaa
0

aab
nnn
1
a a ab
*/
