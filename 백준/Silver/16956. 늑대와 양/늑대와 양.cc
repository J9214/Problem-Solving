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
#define X first
#define Y second
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}
#define modulo 1000000007

int main(){
    FASTIO

    int a,b; cin >> a >> b;
    vector<vector<char>> vec(a,vector<char>(b,-1));
    int id=0;
    for(int i = 0 ; i < a ; i++){
        for(int j = 0; j < b; j++){
            cin >> vec[i][j];
            if(vec[i][j]=='.') vec[i][j]='D';
            if(i>0&&((vec[i][j]=='S'&&vec[i-1][j]=='W')||(vec[i][j]=='W'&&vec[i-1][j]=='S'))) {cout << 0; return 0;}
            if(j>0&&((vec[i][j]=='S'&&vec[i][j-1]=='W')||(vec[i][j]=='W'&&vec[i][j-1]=='S'))) {cout << 0; return 0;}
        }
    }
    cout << 1 << '\n';
    for(int i = 0;  i < a ; i++){
        for(int j = 0 ; j < b; j ++){
            cout << vec[i][j];
        }
        cout << '\n';
    }
}