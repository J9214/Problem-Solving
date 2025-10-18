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

int main(){
    FASTIO

    int n; cin >> n;

    vi vec(n + 1);
    vi dp(301,0);
    for(int i =1 ; i <= n ; i++){
        cin >> vec[i]; 
    }
        
    for(int i =1 ; i <= n; i++){
        int a = 0, b = 0;
        a = vec[i-1] + vec[i];
        if(i >= 3) a += dp[i - 3];
        if(i >= 2) b = dp[i] = dp[i - 2] + vec[i];
        dp[i] = max(a, b);
    }

    cout << dp[n];
}   