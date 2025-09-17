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

int res = 0;
vi visited(9,0);
void func(vi &vec, int d, int s){
    if(s<500) return;
    if(d==vec.size()){res++; return;}

    for(int i = 0 ; i < vec.size(); i++){
        if(visited[i])continue;
        visited[i] = 1;
        func(vec, d+1, s+vec[i]);
        visited[i] = 0;
    }
}
int main(){
    FASTIO

    int n,m;cin >> n >> m;
    vi vec(n);
    for(auto &i : vec) {
        cin >>i;
        i-=m;
    }
    func(vec,0,500);
    cout << res;
}