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
    vvi vec(n,vi(m));
    for(auto &i : vec) for(auto &j : i) {
        char c; cin >> c;
        j=c-'0';
    }

    vi s;
    for(int i = 0 ; i <= 1000; i++) s.push_back(i*i);

    int res =0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < m; j++){
            if(!vec[i][j]) continue;

            int f = min({(i?vec[i-1][j]:0), (i&&j?vec[i-1][j-1]:0), (j?vec[i][j-1]:0)});
            res = max(res,vec[i][j] = *upper_bound(s.begin(),s.end(),f));
        }
    }
    cout << res;
}