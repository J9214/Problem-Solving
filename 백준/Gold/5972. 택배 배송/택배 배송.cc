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
 
    int n,m; cin >> n >> m;
    
    vector<vpi> vec(n+1);
    while(m--){
        int a,b,c; cin >>a>>b>>c;
        vec[a].push_back({c,b});
        vec[b].push_back({c,a});
    }

    vi v(n+1,INT_MAX);
    v[1]=0;

    priority_queue<pi, vpi, greater<pi>> pq;
    pq.push({0,1});

    while(pq.size()){
        auto [cost,curr] = pq.top(); pq.pop();
        
        if(cost > v[curr]) continue;
        
        for(auto [w,next]:vec[curr]){
            if(v[next] <= v[curr]+w) continue;

            v[next] = v[curr] + w;
            pq.push({v[next], next});
        }
    }

    cout << v[n];
}