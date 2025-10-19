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
    vi vec(n),idx(n),lis,res;
    for(auto &i : vec) cin >> i;

    for(int i = 0 ; i < n ; i ++){
        if(lis.empty() || lis.back() < vec[i]) {
            lis.push_back(vec[i]);
            idx[i] = lis.size();
        }
        else {
            auto it = lower_bound(lis.begin(),lis.end(),vec[i]);
            idx[i] = it-lis.begin()+1;
            *it = vec[i];
        }
    }
    int index = lis.size();
    for(auto i = n-1; i >= 0; i--){
        if(idx[i]==index) res.push_back(vec[i]), index--;
    }
    cout << res.size() << '\n';
    for(int i = res.size()-1; i >= 0 ; i--) cout << res[i] << ' ';
}