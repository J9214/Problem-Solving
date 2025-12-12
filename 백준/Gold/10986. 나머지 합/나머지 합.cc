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
void print(vll vec){for(auto i : vec) cout << i << ' ';}

int main(){
    FASTIO
    
    ll n,m; cin >> n >> m;
    ll res =0;
    vll vec(m,-1);
    vec[0] = 0;

    vll arr(n), pre(n);
    for(auto &i : arr) cin >> i;

    for(int i = 0 ; i < n ; i++) {
        pre[i] = arr[i] + (i?pre[i-1]:0);
        ll div = pre[i] % m;
        res += ++vec[div];
    }
    

    cout << res;
}