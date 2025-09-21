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


int n, m; 
vvi vec;
int res = 100000;
vi arr;
void func(int from, int v, int d){
    if(v > res) return;
    if(d == n) res = min(res, v);
    for(int i = 0 ; i < n ; i++){
        if(arr[i] || from == i) continue;
        arr[i] = 1;
        func(i, v+vec[from][i], d+1);
        arr[i] = 0;
    }
}   
int main(){
    FASTIO
    
    cin >> n >> m;
    vec.resize(n,vi(n));
    arr.assign(n,0);

    for(auto &i : vec) for(auto &j :i) cin >> j;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            for(int k = 0 ; k < n ; k++)
                vec[j][k] = min(vec[j][k], vec[j][i] + vec[i][k]);

    arr[m] = 1;
    func(m, 0, 1);
    cout << res;
}