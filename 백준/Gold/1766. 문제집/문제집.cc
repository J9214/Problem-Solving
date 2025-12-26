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
    vvi vec(n+1);
    vi counting(n+1,0);
    while(m--){
        int a,b; cin >> a >> b;
        vec[a].push_back(b);
        counting[b]++;
    }

    priority_queue<int, vi, greater<int>> pq;
    vi res;

    for(int i = 1; i<=n; i++){
        if(counting[i]) continue;
        pq.push(i);
    }

    while(pq.size()){
        int curr = pq.top(); pq.pop();
        res.push_back(curr);

        for(auto j : vec[curr]){
            if(!(--counting[j])) pq.push(j);
        }
    }

    print(res);
}