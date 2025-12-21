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
    
    int n, m, k; cin >> n >> m >> k;
    vi vec(m);
    for(auto &i : vec) cin >> i;

    vi ret;
    for(int i = 0 ; i < n ; i++){
        cout << '?' << ' ' << i+1 << ' ' << i+1 << endl;
        int t; cin >> t;
        ret.push_back((t+1>vec[i]?1:t+1));
    }
    for(int i = 0 ; i < m-n; i++) ret.push_back(1);
    cout << '!' << ' ';
    print(ret); 
    cout << flush;
}