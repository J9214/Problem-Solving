#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<pi>> vvpi;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<ll, ll>> vpll;
typedef struct Point {int x, y;} point;
point direction[4] = {{1,0},{0,1},{-1,0},{0,-1}};
#define modulo 1000000007
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}

#define l(i,n) for(int i = 1 ; i <= n ; i++)
vvi vec;

int main(){
    FASTIO

    int n, m; cin >> n >> m;
    vec.assign(401,vi(401,99999999));

    while(m--){
        int a,b,c; cin >> a >> b >> c;
        vec[a][b]=c;
    }

    int i,j,k;
    l(i,n)l(j,n)l(k,n) vec[j][k] = min(vec[j][k], vec[j][i] + vec[i][k]);
    
    int res = 99999999;
    l(i,n) res = min(res,vec[i][i]);

    if(res == 99999999) cout << -1;
    else cout << res;
}