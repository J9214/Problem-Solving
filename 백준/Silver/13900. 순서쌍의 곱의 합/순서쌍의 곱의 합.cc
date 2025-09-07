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
#define X first
#define Y second
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}
#define modulo 1000000007

int main(){
    FASTIO
    
    ll n; cin >> n;
    ll res = 0;
    vll vec(n),vec1(n);
    for(ll i = 0 ; i < n ; i++){
        cin >> vec[i];
        vec1[i] = vec[i] + (i?vec1[i-1]:0);
    }
    for(int i = 0; i < n ; i++){
        res += vec[i] * (vec1[n-1] - vec1[i]);
    }
    cout << res;
}