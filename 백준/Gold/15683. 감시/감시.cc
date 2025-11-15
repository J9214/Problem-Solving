#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<pi>> vvpi;
typedef vector<pair<int, int>> vpi;

int n,m; 
vvi mat;
struct cam{
    int x;
    int y;
    int dir;
};
vector<cam> camera;

vvpi ret_dir(int i){
    vvpi v1 = {{{1,0}}, {{0,1}}, {{-1,0}}, {{0,-1}}};
    vvpi v2 = {{{1,0},{-1,0}}, {{0,1}, {0,-1}}};
    vvpi v3 = {{{1,0},{0,-1}}, {{0,-1},{-1,0}}, {{-1,0},{0,1}}, {{0,1},{1,0}}};
    vvpi v4 = {{{1,0},{0,-1},{-1,0}}, {{0,-1},{-1,0},{0,1}}, {{-1,0},{0,1},{1,0}}, {{0,1},{1,0},{0,-1}}};
    vvpi v5 = {{{1,0},{0,-1},{-1,0},{0,1}}};

    vector<vvpi> vec{v1,v2,v3,v4,v5};

    return vec[i-1];
}

int searching(int x, int y, pi dir){ 
    if(x<0||y<0||x>=n||y>=m||mat[x][y]==-1) return 0;
    int curr = !mat[x][y];
    
    int nx = x + dir.first;
    int ny = y + dir.second;
    
    mat[x][y]++;
    int ret = searching(nx,ny,dir);

    return curr + ret;
}

void desearching(int x, int y, pi dir){ 
    if(x<0||y<0||x>=n||y>=m||mat[x][y]==-1) return;

    int nx = x + dir.first;
    int ny = y + dir.second;

    desearching(nx,ny,dir);
    mat[x][y]--;
}

int func(int idx){ 
    if(idx == (int)camera.size()) return 0;
    vvpi cam_find = ret_dir(camera[idx].dir);
    int res=0;
    
    for(auto vec : cam_find){ 
        int ret = 0;

        for(auto v : vec){ 
            ret += searching(camera[idx].x, camera[idx].y, v);
        }

        int next = func(idx+1);
        res = max(res, ret + next);   
        
        for(auto v : vec){ 
            desearching(camera[idx].x, camera[idx].y, v);
        }
    }
    
    return res;
}

int main(){
    FASTIO
    
    cin >> n >> m;
    int total = n*m;
    mat.resize(n, vi(m));

    for(int i = 0 ; i < n ; i++){
        for(int j = 0;  j< m  ; j++){
            cin >> mat[i][j];
            if(mat[i][j]){
                if(mat[i][j] == 6) {
                    mat[i][j] = -1;
                    total--;
                }
                else {
                    camera.push_back({i,j,mat[i][j]});
                    mat[i][j] = 0;
                }
            }
        }
    }  

    cout << total - func(0) ;
}