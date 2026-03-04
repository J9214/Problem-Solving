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

int n, m ,r; 
vvi vec;
vi rot;
vvi res;
void func(int d){
    rot.clear();
    
    for(int i = d; i < n-d; i++) rot.push_back(vec[i][d]);
    for(int i = d+1; i < m-d-1; i++) rot.push_back(vec[n-d-1][i]);
    for(int i = n-d-1; i >= d; i--) rot.push_back(vec[i][m-d-1]);
    for(int i = m-d-2; i >= d+1; i--) rot.push_back(vec[d][i]);
}

void rot_func(int d){
    int s = rot.size();
    if(!s) return;
    int idx = (s-(r%s))%s;
    
    for(int i = d; i < n-d; i++, idx=(idx+1)%s) res[i][d]=rot[idx];
    for(int i = d+1; i < m-d-1; i++, idx=(idx+1)%s) res[n-d-1][i]=rot[idx];
    for(int i = n-d-1; i >= d; i--, idx=(idx+1)%s) res[i][m-d-1]=rot[idx];
    for(int i = m-d-2; i >= d+1; i--, idx=(idx+1)%s) res[d][i]=rot[idx];
}
int main(){
    FASTIO
    
    cin >> n >> m >>r;
    vec.resize(n,vi(m));
    res.resize(n,vi(m));
    for(auto &i : vec) for(auto &j:i) cin >> j;

    for(int i = 0 ; i < min(n,m)/2; i++){
        func(i);
        rot_func(i);    
    }

    print(res);
    
}