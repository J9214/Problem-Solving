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

    int n,m,x; cin >> n >> m >> x;
    vvi vec(n+1,vi(n+1,100000));
    int a,b,c;
    for(int i = 0; i <= n ; i++) vec[i][i] = 0;
    while(m-- && cin >> a >> b >> c)
        vec[a][b] = c;

    for(int i = 1 ; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <=n ; k++)
                vec[j][k] = min(vec[j][k], vec[j][i] + vec[i][k]);

    int res = 0;
    for(int i = 1 ; i <= n ; i++)
        res = max(res, vec[i][x] + vec[x][i]);
    

    cout << res;
}