#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<pi>> vvpi;
typedef vector<pair<int, int>> vpi;
typedef struct Point {int x, y;} point;
point direction[4] = {{1,0},{0,1},{-1,0},{0,-1}};

int n, m, res;
vvi vec,t_vec;
vvi wall;
vvi visited, t_visited;

int main(){
    FASTIO

    cin >> n >> m;
    res = 99999999;
    vec.assign(n,vi(m,0));
    t_vec.assign(n,vi(m,0));
    wall.resize(n, vi(m));
    visited.assign(n,vi(m,0));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            char c; cin >> c;
            wall[i][j] = {c-'0'};
        }
    }

    queue<point> q;
    q.push({0,0});

    vec[0][0]= 1;
    visited[0][0] = 1;

    while(q.size()){
        auto [x,y] = q.front(); q.pop();

        for(auto dir : direction){
            int nx = x + dir.x;
            int ny = y + dir.y;
            if(nx<0||ny<0||nx>=n||ny>=m||visited[nx][ny]) continue;

            visited[nx][ny] = 1;
            vec[nx][ny] = vec[x][y] + 1;
            if(!wall[nx][ny]) q.push({nx,ny});
        }
    }
    
    q.push({n-1,m-1});

    t_vec[n-1][m-1] = 1;
    visited[n-1][m-1] = 2;
    while(q.size()){
        auto [x,y] = q.front(); q.pop();

        for(auto dir : direction){
            int nx = x + dir.x;
            int ny = y + dir.y;
            if(nx<0||ny<0||nx>=n||ny>=m||visited[nx][ny]==2) continue;

            visited[nx][ny] = 2;
            t_vec[nx][ny] = t_vec[x][y] + 1;
            if(!wall[nx][ny]) q.push({nx,ny});
        }
    }

    for(int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < m ; j++)
            if(vec[i][j] && t_vec[i][j]) res = min(res, vec[i][j]+t_vec[i][j]-1);

    if(res!=99999999) cout << res;
    else cout << -1;
}