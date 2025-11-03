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
void print(vi vec){for(auto i : vec) cout << i << '\n';}

int main(){
    FASTIO

    int n,m,k,x;cin >> n >> m >> k >> x;
    vvi vec(n+1);
    while(m--){
        int a,b;cin >> a >> b;
        vec[a].push_back(b);
    }

    vi res;
    vi visit(n+1,0);
    queue<pi> q;
    q.push({x,0});

    while(!q.empty()){
        auto [a,b] = q.front(); q.pop();
        if(b==k) res.push_back(a);
        
        for(int i = 0 ; i < vec[a].size(); i++){
            if(visit[vec[a][i]]||vec[a][i]==x) continue;
            visit[vec[a][i]] = b+1;
            q.push({vec[a][i],b+1});
        }
    }

    sort(res.begin(), res.end());
    if(res.size()) print(res);
    else cout << -1;
}