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
void print(vvll mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}

int main(){
    FASTIO

    ll n,m,k; cin >> n >> m >> k;
    vvll vec(n+1, vll(m+1,1));

    for(int i  = 1 ; i <= n ; i++)
        for(int j = 1; j  <= m ; j++)
            vec[i][j] = min((ll)1000000001, vec[i-1][j] + vec[i][j-1]);

    if(k>vec[n][m]) {cout << -1; return 0;}

    int i = n, j = m;
    string res = "";
    while(n||m){
        if(!n) res += "z", m--;
        else if(!m) res += "a", n--;
        else if(k<=vec[n-1][m]) res += "a", n--;
        else res += "z", k-=vec[n-1][m], m--;
    }
    cout << res;
}
