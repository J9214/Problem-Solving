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

vi vec;
set<vi> s;
vi res;
vi visited;
int n,m;
void func(int d, int idx){
    if(d==m) {
        s.insert(res);
        return;
    }

    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
        res[d] = vec[i];
        visited[i] = 1;
        func(d+1, i+1);
        visited[i] = 0;
    }
    
}
int main(){
    FASTIO
 
    cin >> n >> m;
    vec.resize(n);
    visited.assign(n,0);
    res.resize(m);
    for(auto &i:vec) cin >> i;    
    sort(vec.begin(),vec.end());
    func(0,0);

    for(auto i : s){
        print(i); cout << '\n';
    }
}