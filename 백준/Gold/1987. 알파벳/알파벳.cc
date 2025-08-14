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

bitset<26> bit;
vector<vector<char>> vec;
int res = 0;
void bfs(int i, int j, int depth){
    bit[vec[i][j]-'A']=1;
    res = max(depth,res);

    for(auto d : direction){
        int x = i + d.x;  int y = j + d.y;
        if(x<0||y<0||x>=vec.size()||y>=vec[0].size()||bit[vec[x][y]-'A']) continue;

        bfs(x,y,depth+1);
    }
    bit[vec[i][j]-'A']=0;
}
int main(){
    FASTIO
    
    int n,k; cin >> n >> k;
    vec.resize(n,vector<char>(k));
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < k ;  j++) cin >> vec[i][j];
    
    bfs(0,0,1);

    cout << res;
} 