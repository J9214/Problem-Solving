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

vvi mat_mult(vvi vec1, vvi vec2, long long n){
    vvi vec(n, vector<int>(n, 0));

    for(int i = 0 ; i < n; i++) for(int j = 0 ; j < n ; j++) for(int k = 0 ; k < n ; k++)
        vec[i][j] += vec1[i][k] * vec2[k][j];

    return vec;
}

int main(){
    FASTIO

    int n; cin >> n;
    vvi mat(n, vi(n,0));

    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j++){
            char c; cin >> c;
            if(c=='Y') mat[i][j] = 1;
        }
    }
    vvi check = mat;
    ll res=0;
    mat = mat_mult(mat, mat, n);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(mat[i][j]) check[i][j] = 1;
        }
    }
    for(auto v : check) res = max(res, (ll)count(v.begin(),v.end(),1)-1);
    cout << res;
}