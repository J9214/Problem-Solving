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

    int n,m; cin >> n >> m;
    vvi vec(m,vi(n,0));
    vvi map(m,vi(n));
    for(int i = 0; i <m ; i++)
        for(int j = 0;  j < n ; j++){
            char c; cin >> c;
            map[i][j]=c-'0';
        }
        

    vec[0][0]=0;
    map[0][0]=-1;
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> q; 
    q.push({0,0,0});

    while(q.size()){
        auto [num,x,y] = q.top(); q.pop();

        for(auto dir : direction){
            int nx = x+dir.x;
            int ny = y+dir.y;

            if(nx<0||ny<0||nx>=m||ny>=n||map[nx][ny]==-1) continue;

            vec[nx][ny] = vec[x][y] + map[nx][ny];
            map[nx][ny] = -1;
            q.push({vec[nx][ny],nx,ny});
        }   
    }

    cout << vec[m-1][n-1] << '\n';
}