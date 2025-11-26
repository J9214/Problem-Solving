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
void print(vi vec){for(auto i : vec) cout << i << '\n';}

int main(){
    FASTIO
    
    ll n; cin >> n;
    vi vec;
    for(ll i = 1; i <= 100000; i++){
        ll p = i*i;
        if(i*i<=n) continue;
        ll sq = sqrt(p-n);
        if(sq*sq==p-n) vec.push_back(i);
    }
    if(vec.size()) print(vec);
    else cout << -1;
}