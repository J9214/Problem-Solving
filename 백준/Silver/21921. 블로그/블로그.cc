#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<ll, ll>> vpll;
typedef struct Point {int x, y;} point;
point direction[4] = {{1,0},{0,1},{-1,0},{0,-1}};
#define modulo 1000000007
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}

int main(){
    FASTIO
 
    int n, m; cin >> n >> m;
    vi vec(n);
    for(auto &i : vec) cin >> i;
    int res=0;
    int day=0;
;    int t=0;

    for(int i = 0 ; i < n ; i++){
        t+=vec[i];
        if(i>=m) t -= vec[i-m];

        if(res == t) day++;
        else if(res<t)day = 1;
        
        res = max(res, t);
    }


    if(res == 0) cout << "SAD";
    else cout << res << '\n' << day;
}