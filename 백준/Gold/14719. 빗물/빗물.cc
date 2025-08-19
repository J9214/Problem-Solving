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
    
    int n,m,res=0; cin >> n >> m;
    vvi vec(n,vi(m,0));
    for(int i = 0 ; i < m; i++){
      int d; cin >> d;
      for(int j = d-1; j >= 0; j--) vec[j][i] = 1;
    }
    
    for(int i = n-1; i >= 0; i--){
      int idx = -1;
      for(int j = 0 ; j < m ; j++){
        if(idx!=-1&&vec[i][j])
          res+= j-idx-1;
        if(vec[i][j]) idx = j;
      }
    }
    cout << res;
}