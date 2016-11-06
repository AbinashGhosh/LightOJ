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

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T;
    stack<string>b,f;
    string cmd,url;
    scanf("%d\n",&T);
    FOR(t,1,T)
    {
        b.push("http://www.lightoj.com/");
        printf("Case %d:\n",t);
        while(1)
        {
        cin>>cmd;
        if(cmd=="VISIT")
        {
            cin>>url;
            b.push(url);
            printf("%s\n",url.c_str());
            while(!f.empty())f.pop();
        }
        else if(cmd=="BACK")
        {
            if(b.size()>1)
            {
               f.push(b.top());
               b.pop();
               cout<<b.top()<<"\n";
            }
            else
            printf("Ignored\n");
        }
        else if(cmd=="FORWARD")
        {
            if(f.size()>=1)
            {
               b.push(f.top());
               f.pop();
               cout<<b.top()<<"\n";
            }
            else
            printf("Ignored\n");
        }
        else if(cmd=="QUIT")
        break;
        }
        while(!f.empty())f.pop();
        while(!b.empty())b.pop();
    }
    return 0;
}

