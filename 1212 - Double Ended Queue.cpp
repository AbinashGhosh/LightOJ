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
    int test, ctc = 1, val, n, ins, i, id=0;
    string com;
    map<string,int> m;
    m["pushLeft"] = id++;
    m["pushRight"] = id++;
    m["popLeft"] = id++;
    m["popRight"] = id++;
    deque<int>q;
    scanf("%d",&test);
    while(test--)
    {
        q.clear();
        printf("Case %d:\n", ctc++);
        scanf("%d %d",&n,&ins);
        for(i = 0; i<ins; i++)
        {
            cin >> com;
            switch(m[com])
            {
            case 0:
                cin >> val;
                if(q.size()==n)printf("The queue is full\n");
                else q.push_front(val), printf("Pushed in left: %d\n", val);
                break;
            case 1:
                cin >> val;
                if(q.size()==n)printf("The queue is full\n");
                else q.push_back(val), printf("Pushed in right: %d\n",val);
                break;
            case 2:
                if(q.empty())printf("The queue is empty\n");
                else printf("Popped from left: %d\n",q.front()),q.pop_front();
                break;
            case 3:
                if(q.empty())printf("The queue is empty\n");
                else printf("Popped from right: %d\n",q.back()),q.pop_back();
                break;
            default:
                break;
            }
        }
    }
    return 0;
}

