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

    int n; cin >> n;
    vi vec(n);
    vi dp(n,0);

    int idx=0;
    for(int i = 0 ; i < n ; i ++){
        cin >> vec[i];
        int l = 0;
        for(int j = 0 ; j < i; j++){
            if(vec[j] < vec[i]) l = max(dp[j],l);
        }
        dp[i] = l + 1;

        if(dp[idx] <= l) idx = i;
    }

    vi res(dp[idx]);
    for(int i=n-1, t=dp[idx]; i >=0 ; i--){
        if(dp[i] == t) res[t-1] = vec[i], t--;
    }
    cout << dp[idx] << '\n';
    print(res);
}