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

    int n; cin >> n;
    vector<vector<char>> vec(n,vector<char>(n));
    for(auto &i:vec)for(auto &j :i) cin >> j;

    int t; cin >> t;
    if(t==1){
        for(auto &i:vec){
            for(auto &j :i) cout << j;
            cout << '\n';
        }
    }
    if(t==2){
        for(int i = 0 ; i < n; i++){
            for(int j = n-1; j>=0; j--) cout << vec[i][j];
            cout << '\n';
        }
    }
    if(t==3){
        for(int i = n-1 ; i >=0; i--){
            for(int j = 0; j < n ; j++) cout << vec[i][j];
            cout << '\n';
        }
    }
}