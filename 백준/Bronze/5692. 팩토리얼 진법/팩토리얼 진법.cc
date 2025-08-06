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
    
    vi vec(6,0);
    vec[1] = 1;
    for(int i = 2; i < vec.size() ; i++) vec[i] = vec[i-1]*i;
    int n;
    while(cin>>n){
        if(!n) break;
        int res = 0;
        for(int i = 1; n > 0 ; i++){
            res += n%10 * vec[i];
            n/=10;
        }
        cout << res << '\n';
    }
}