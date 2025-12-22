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

vi visited;
vvi vec;
int num = 1;
void dfs(int node){
    if(!visited[node]) visited[node] = num++;
    sort(vec[node].begin(), vec[node].end());

    for(auto &i : vec[node]){
        if(!visited[i])
            dfs(i);
    }
}

int main(){
    FASTIO

    int n,m,l; cin >> n >> m >>l;
    visited.assign(n+1,0);
    vec.resize(n+1);

    while(m--){
        int a,b;cin >> a >>b;
        vec[a].push_back(b);    
        vec[b].push_back(a);
    }

    dfs(l);

    for(int i = 1 ; i <= n ; i++) cout << visited[i] << '\n';
}