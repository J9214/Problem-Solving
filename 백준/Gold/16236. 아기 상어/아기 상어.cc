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
point direction[4] = {{-1,0},{0,-1},{0,1},{1,0}};
#define modulo 1000000007
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}

struct st{
    int x,y,d;
};

int n, _size=2, _size_c=0;
vvi vec;
vvi visited;

st find(int x, int y){
    queue<st> q;
    q.push({x,y,0});
    visited.assign(n,vi(n,0));
    visited[x][y] = 1;
    st bestP={-1,-1,INT_MAX};

    while(q.size()){
        auto curr = q.front(); q.pop();

        if(bestP.d<curr.d) continue;

        for(auto dir : direction){
            int nx = curr.x + dir.x;
            int ny = curr.y + dir.y;

            if(nx<0||ny<0||nx>=n||ny>=n||visited[nx][ny]||vec[nx][ny]>_size) continue;

            visited[nx][ny] = 1;
            int nd = curr.d+1;

            if(vec[nx][ny]&&vec[nx][ny]<_size)
                if(nd < bestP.d || (nd==bestP.d && (nx < bestP.x || (nx == bestP.x && ny < bestP.y)))) 
                    bestP={nx,ny,nd};

            q.push({nx,ny,curr.d+1});
        }
    }
    return bestP;
}

int main(){
    FASTIO

    cin >> n;
    vec.resize(n,vi(n));
    int x,y;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> vec[i][j]; 
            if (vec[i][j] == 9) x=i,y=j,vec[i][j]=0;
        }
    }

    find(x,y);
    int res = 0;
    st p;

    while(1){
        p = find(x,y);
        if(p.x==-1 && p.y==-1) break;
        
        res += p.d;

        x = p.x;
        y = p.y;

        if(++_size_c == _size){
            ++_size;
            _size_c = 0;
        }
        
        vec[x][y] = 0;
        
        
    }
    cout << res;
}