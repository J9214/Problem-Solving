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

vpi teacher;
bool b= 0;

bool obj(vector<vector<char>> &vec){
    for(auto &t : teacher){
        for(int i = t.first; i >= 0; i--){
            if(vec[i][t.second]=='O')break;
            if(vec[i][t.second]=='S')return 0;
        }
        for(int i = t.first; i < vec.size(); i++){
            if(vec[i][t.second]=='O')break;
            if(vec[i][t.second]=='S')return 0;
        }
        for(int i = t.second; i >= 0; i--){
            if(vec[t.first][i]=='O')break;
            if(vec[t.first][i]=='S')return 0;
        }
        for(int i = t.second; i < vec.size(); i++){
            if(vec[t.first][i]=='O')break;
            if(vec[t.first][i]=='S')return 0;
        }
    }
    return 1;
}

void func(vector<vector<char>> &vec, int x ,int y, int d){
    if(b) return;

    if(d==3){
        b = obj(vec);
        return;
    }
    for(int i = x;  i< vec.size() ;i++){
        for(int j =y ;  j < vec[0].size(); j++){
            if(vec[i][j] == 'X'){
                vec[i][j] = 'O';
                func(vec, x, y + 1, d+1);
                vec[i][j] = 'X';
            }
        }
        y= 0;
    }
}


int main(){
    FASTIO

    int n; cin >> n;
    
    vector<vector<char>> vec(n, vector<char>(n));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> vec[i][j];
            if(vec[i][j]=='T') teacher.push_back({i,j});
        }
    }

    func(vec,0,0,0);
    cout << (b?"YES":"NO");
}