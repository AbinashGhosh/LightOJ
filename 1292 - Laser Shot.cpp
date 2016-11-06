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

const int NN = 705;

int cases, caseno, n;

pair <int, int> P[NN], Q[NN];

int main() {

    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d", &n);
        for( int i = 0; i < n; i++ ) scanf("%d %d", &P[i].first, &P[i].second);

        int res = 0;
        for( int i = 0; i < n; i++ ) {
            int k = 0;
            for( int j = i + 1; j < n; j++ ) {
                Q[k].first = P[j].first - P[i].first;
                Q[k].second = P[j].second - P[i].second;
                int d = __gcd( abs(Q[k].first), abs(Q[k].second) );
                Q[k].first /= d;
                Q[k].second /= d;
                if( Q[k].first < 0 ) {
                    Q[k].first *= -1;
                    Q[k].second *= -1;
                }
                if( Q[k].first == 0 && Q[k].second < 0 ) Q[k].second *= -1;
                k++;
            }
            int mx = 0;
            sort( Q, Q + k );
            for( int x = 0, y; x < k; x++ ) {
                for( y = x; y < k; y++ ) if( Q[x] != Q[y] ) break;
                mx = max( mx, y - x );
                x = y - 1;
            }
            res = max( res, mx + 1 );
        }
        printf("Case %d: %d\n", ++caseno, res);
    }
    return 0;
}


