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
    
    for(int t= 0; t < 3; ++t){
        int n; cin >> n;
        int total = 0;
        vi vec;
        for(int i = 0 ; i < n ; i++){
            int a,b; cin >> a >> b;
            total += a*b;
            for(int j = 1; b >= j; j*=2, b-=j)
                vec.push_back(j*a);
            if(b) vec.push_back(a*b);
        }

        if(total%2){cout << 0 << '\n'; continue;}

        bitset<50001> dp;
        dp[0] = 1;
        for(auto i : vec) dp |= (dp<<i);
        
        cout << dp[total/2] << '\n';
    }
    
}