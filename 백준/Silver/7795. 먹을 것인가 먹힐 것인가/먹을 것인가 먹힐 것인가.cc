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
 
    int t; cin  >> t;
    while(t--){
        int n,m; cin >> n >> m;
        vi v1(n),v2(m);
        for(auto &i:v1) cin >> i;
        for(auto &i:v2) cin >> i;
        sort(v2.begin(),v2.end());

        int res = 0;
        for(auto i:v1)res+=lower_bound(v2.begin(),v2.end(),i)-v2.begin();
        
        cout << res << '\n';
    }

}