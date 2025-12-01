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

vpi vec;
int res = 1000000000;

void func(int idx, int d, int m, int a, int b){
    if(d==m) {
        res = min(res, abs(a-b));
        return;
    }

    for(int i = idx; i < vec.size(); i++)
        func(i+1, d+1, m, a*vec[i].first, b+vec[i].second);
    
}
int main(){
    FASTIO

    int n; cin >> n;
    vec.resize(n);

    for(auto &i : vec) cin >> i.first >> i.second;

     for(int i = 1 ; i <=n ; i++)
        func(0,0,i,1,0);
    
    cout << res;
}