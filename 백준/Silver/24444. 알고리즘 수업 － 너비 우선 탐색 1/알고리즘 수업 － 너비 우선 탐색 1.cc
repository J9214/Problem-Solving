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

vvi vec;
vi visited;
int co = 2;

void bfs(int k){
    visited[k] = 1;
    queue<int> q;

    q.push(k);

    while(q.size()){
        auto c = q.front(); q.pop();

        sort(vec[c].begin(),vec[c].end());
        for(auto &i : vec[c]){
            if(visited[i]) continue;
            
            visited[i]=co++;
            q.push(i);
        }
    }
    
}
int main(){
    FASTIO

    int n,m,k; cin >> n >> m >> k;
    vec.resize(n+1);
    visited.assign(n+1,0);

    while(m--){
        int a,b;cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    bfs(k);
    for(int i = 1; i < visited.size(); i++) cout << visited[i] << '\n';
}