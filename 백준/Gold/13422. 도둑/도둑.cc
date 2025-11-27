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
void print(vll vec){for(auto i : vec) cout << i << ' ';}

int main(){
    FASTIO

    int t; cin >> t;
    while(t--){
        ll n,m,k; cin >> n >> m >> k;
        ll t=0;
        vll vec(n+m);
        for(int i = 0 ; i < n ; i ++) {
            cin >> vec[i];
            t+=vec[i];
        }
        if(n==m&&t<k) {
            cout << 1 << '\n';
            continue;
        }
        for(int i = n; i < n + m; i++) vec[i] = vec[i-n];
        ll res=0;
        for(int i = 1; i < vec.size(); i++){
            vec[i] += vec[i-1];
            if(i>=m){
                // vec[i]-=vec[i-m];
                if(vec[i]-vec[i-m]<k)res++;
            }
        }
        //print(vec); cout << '\n';
        cout << res << '\n';
    }
}