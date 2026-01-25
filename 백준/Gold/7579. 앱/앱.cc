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
void print(vpi vec){for(auto i : vec) cout << i.first << ' ' << i.second << '\n';}

int main(){
    FASTIO
    
    int n,m ;cin >> n >> m ;
    vpi vec(n);
    int t = 0;
    for(auto &i : vec) cin >> i.second;
    for(auto &i : vec) {cin >> i.first; t+=i.first;}
    vi dp(t+1,0);

    for(int i = 0 ; i < n ; i++)
        for(int j = t; j>=vec[i].first; j--)
            dp[j] = max(dp[j], dp[j-vec[i].first]+vec[i].second);
    
    for(int i = 0 ; i < t+1; i++){
        if(dp[i]>=m) {
            cout << i;
            return 0;
        }
    }

}