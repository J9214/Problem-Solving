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
    
    int n,m,x,y; cin >>  n >> m >> x >> y;
    vvi vec(n+x,vi(m+y));
    for(int i = 0 ; i < n + x; i++)
        for(int j = 0 ; j < m + y; j++)
            cin >> vec[i][j];

    for(int i = x ; i < n; i++)
        for(int j = y ; j < m ; j++)
            vec[i][j] = vec[i][j]-vec[i-x][j-y];
    
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m ; j++){
            cout << vec[i][j] << ' ';
        }
        cout << '\n';
    }
}