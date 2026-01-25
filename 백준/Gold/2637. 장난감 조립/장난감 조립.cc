#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<pi>> vvpi;
typedef vector<vector<ll>> vvll;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<ll, ll>> vpll;
typedef struct Point {int x, y;} point;
point direction[4] = {{1,0},{0,1},{-1,0},{0,-1}};
#define modulo 1000000007
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}

int n,m;
vvpi tree;
vi visited(101,0);
vvi vec(101,vi(101,0));

void vec_sum(vi &a, vi &b, int r){
    for(int i = 0 ; i < a.size(); i++)
        a[i]+=b[i]*r;
}

void func(int node, int r){
    visited[node] = 1;

    if(tree[node].empty()) {
        vec[node][node] = 1;
        return;
    }

    for(auto &i : tree[node]){
        if(!visited[i.first]) func(i.first,i.second);
        vec_sum(vec[node], vec[i.first], i.second);
    }
}

int main(){
    FASTIO

    cin >> n >> m;

    tree.resize(n+1);
    while(m--){
        int a,b,c; cin >> a >> b >> c;
        tree[a].push_back({b,c});
    }
    
    func(n, 1);
    for(int i = 0  ; i < vec[n].size(); i++) 
        if(vec[n][i]) cout << i << ' ' << vec[n][i] << '\n';
}