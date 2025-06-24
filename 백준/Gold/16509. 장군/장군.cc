#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<pi>> vvpi;
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

    point route[8][3] = {
        {{-1,0},{-2,-1},{-3,-2}},
        {{-1,0},{-2,1},{-3,2}},
        {{1,0},{2,-1},{3,-2}},
        {{1,0},{2,1},{3,2}},
        {{0,-1},{-1,-2},{-2,-3}},
        {{0,-1},{1,-2},{2,-3}},
        {{0,1},{-1,2},{-2,3}},
        {{0,1},{1,2},{2,3}}
    };

    int sx,sy,kx,ky; cin >>sx>>sy>>kx>>ky;
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> q;
    q.push({0,sx,sy});
    vvi vec(10,vi(9,0));
    vec[kx][ky] = 1;
    
    while(q.size()){
        auto [cnt,x,y] = q.top(); q.pop();
        vec[x][y] = -1;

        for(int i=0; i<8; i++){
            int f=0;
            for(int j = 0 ; j < 2;j++){ // 경로상 지나갈 수 있는지
                int tx = x + route[i][j].x;
                int ty = y + route[i][j].y;

                if(tx<0||ty<0||tx>9||ty>8||vec[tx][ty]==1) f=1;    
            }
            if(!f){ // 경로 끝에 갈 수 있는지
                int nx = x + route[i][2].x;
                int ny = y + route[i][2].y;
                if(nx<0||ny<0||nx>9||ny>8||vec[nx][ny]==-1) continue;    
                if(vec[nx][ny] == 1) {cout << cnt + 1; return 0;}
                vec[nx][ny] = -1;
                q.push({cnt+1,nx,ny});    
            }
        }
    }
    cout << -1;
}