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

int n, m, res=99999999; 

int main(){
    FASTIO

    cin >> n >> m;
    int vec[n][m][4] = {};

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            char c; cin >> c;
            vec[i][j][2]= {c-'0'};
        }
    }

    queue<point> q;
    q.push({0,0});

    vec[0][0][0]= 1;
    vec[0][0][3] = 1;

    while(q.size()){
        auto [x,y] = q.front(); q.pop();

        for(auto dir : direction){
            int nx = x + dir.x;
            int ny = y + dir.y;
            if(nx<0||ny<0||nx>=n||ny>=m||vec[nx][ny][3]) continue;

            vec[nx][ny][3] = 1;
            vec[nx][ny][0] = vec[x][y][0] + 1;
            if(!vec[nx][ny][2]) q.push({nx,ny});
        }
    }
    
    q.push({n-1,m-1});

    vec[n-1][m-1][1] = 1;
    vec[n-1][m-1][3] = 2;

    while(q.size()){
        auto [x,y] = q.front(); q.pop();

        for(auto dir : direction){
            int nx = x + dir.x;
            int ny = y + dir.y;
            if(nx<0||ny<0||nx>=n||ny>=m||vec[nx][ny][3]==2) continue;

            vec[nx][ny][3] = 2;
            vec[nx][ny][1] = vec[x][y][1] + 1;
            if(!vec[nx][ny][2]) q.push({nx,ny});
        }
    }

    for(int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < m ; j++)
            if(vec[i][j][0] && vec[i][j][1]) res = min(res, vec[i][j][0]+vec[i][j][1]-1);

    if(res!=99999999) cout << res;
    else cout << -1;
}