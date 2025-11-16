#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpi;
typedef struct Point {
    int x, y; 
    bool operator!=(const Point &d) const{
        return !(x==d.x && y==d.y);
    }
} point;
point dir[4] = {{1,0},{0,1},{-1,0},{0,-1}};

struct dust{
    int x;
    int y;
    int amount;
};

vvi vec;
queue<dust> q;
int n,m,t; 
point m_idx;
void diffuse(){
    while(q.size()){
        auto [x,y,d] = q.front(); q.pop();
        int diffuse_amount=d/5;
        if(!diffuse_amount) continue;

        for(auto d : dir){
            int nx = x+d.x;
            int ny = y+d.y;
            if(nx<0||ny<0||nx>=n||ny>=m||vec[nx][ny]==-1) continue;
            
            vec[nx][ny] += diffuse_amount;
            vec[x][y] -= diffuse_amount;
        }
    }
}

void find_dust(){
    for(int i = 0; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            if(vec[i][j] > 0) q.push({i,j,vec[i][j]});
}

void cleaning(){
    point u_idx = {m_idx.x-1,0};
    point g_idx = {m_idx.x,1};
    int d = 2;
    while(u_idx!=g_idx){
        if(u_idx.x+dir[d].x<0||u_idx.y+dir[d].y<0||u_idx.x+dir[d].x>g_idx.x||u_idx.y+dir[d].y>=m) 
            d=(d+3)%4;
        int nx = u_idx.x+dir[d].x;
        int ny = u_idx.y+dir[d].y;
        
        vec[u_idx.x][u_idx.y]=vec[nx][ny];
        u_idx={nx,ny};
    }
    vec[g_idx.x][1] = 0;

    u_idx = {m_idx.x+2,0};
    g_idx = {m_idx.x+1,1};
    d = 0;
    while(u_idx!=g_idx){
        if(u_idx.x+dir[d].x<g_idx.x||u_idx.y+dir[d].y<0||u_idx.x+dir[d].x>=n||u_idx.y+dir[d].y>=m) 
            d=(d+5)%4;
        int nx = u_idx.x+dir[d].x;
        int ny = u_idx.y+dir[d].y;

        vec[u_idx.x][u_idx.y]=vec[nx][ny];
        u_idx={nx,ny};
    }
    vec[g_idx.x][1] = 0;
}
int main(){
    FASTIO

    cin >> n >> m >> t;
    vec.resize(n,vi(m));
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0; j < m ; j++){
            cin >> vec[i][j];
            if(vec[i][j]==-1) m_idx={i-1,1};
        }
    }
    while(t--){
        find_dust();
        diffuse();
        cleaning();
    }

   
    int res = 0;
    for(auto i:vec) for(auto j:i) res += j>0?j:0;
    cout << res;
}