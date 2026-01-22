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

    int n,m ;cin >> n >> m;
    vvi vec(n,vi(m));
    vvi visited(n,vi(m,0));
    int total = 0;
    
    for(auto &i :vec) for(auto &j : i) {
        cin >> j;
        total+=j;
    }

    int prev=total;

    int time=1;
    queue<pi> qq;
    queue<pi> q; 

    while(total){
        q.push({0,0});
        prev = total;

        while(q.size()){
            auto [x,y] = q.front(); q.pop();
            visited[x][y] = time;
            
            for(auto dir: direction){
                int nx = x + dir.x;
                int ny = y + dir.y;
                if(nx<0||ny<0||nx>=n||ny>=m||visited[nx][ny]==time) continue;
                
                visited[nx][ny]=time; 
                
                if(vec[nx][ny]==1)
                    qq.push({nx,ny});
                
                if(vec[nx][ny]==0)
                    q.push({nx,ny});
            }     
        }

        while(qq.size()){
            auto [x,y] = qq.front(); qq.pop();
            if(vec[x][y]==1){
                vec[x][y]=0;
                total--;
            }
        }

        time++;
    }
    
    cout << time-1 << '\n' << prev;
}