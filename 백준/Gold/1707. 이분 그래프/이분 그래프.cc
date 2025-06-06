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
#define X first
#define Y second
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}
#define modulo 1000000007

void bfs(vvi &graph, vi &node){
    queue<int> q;
    
    for(int j = 1; j < node.size(); j++){
        if(node[j]) continue;
        q.push(j);
        node[j] = 1;
        
        while(q.size()){
            int curr=q.front(); q.pop();
            
            for(auto i : graph[curr]){
                if(node[i] && node[i]%2 == node[curr]%2){cout << "NO\n"; return;}
                else if(!node[i]){
                    node[i] = node[curr]+1;
                    q.push(i);
                }
            }
        }
    }

    cout << "YES\n";
}
int main(){
    FASTIO

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vvi graph(n+1);
        vi node(n+1,0);
        for(int i= 0; i < m ; i++){
            int a,b;cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
             
        bfs(graph, node);
    }
}