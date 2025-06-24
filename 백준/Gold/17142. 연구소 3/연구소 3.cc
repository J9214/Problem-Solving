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

vector<tuple<int,int,int>> birus;
vector<tuple<int,int,int>> active_birus;
vi visited;

priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> q;
int n, m;
int res=INT_MAX;
int emp;
int bfs(vvi vec){
    int ret=0;
    int fill=birus.size();

    while(q.size()){
        auto [day,x,y] = q.top(); q.pop();    
        vec[x][y] = 1;

        for(auto dir : direction) {
            int nx = x + dir.x;
            int ny = y + dir.y;

            if(nx<0||ny<0||nx>=n||ny>=n||vec[nx][ny]==1) continue;
            if(vec[nx][ny]==0) fill++;
            vec[nx][ny] = 1;
            q.push({day+1,nx,ny});
            if(fill==emp) return day;
        }
    }

    return INT_MAX;
}
void active(int c, int idx, vvi &vec){
    if(c==m){
        for(auto i : active_birus) q.push(i);
        int t = bfs(vec);
        res = min(t,res);
        return;
    }
    for(int i = idx ; i < birus.size() ; i++){
        if(visited[i]) continue;
        visited[i] = 1;
        active_birus[c] = birus[i];
        active(c+1, i+1, vec);
        visited[i] = 0;
    }
}
int main(){
    FASTIO
    
    cin >> n >> m;
    vvi vec(n,vi(n));
    emp = n*n;
    int t = 0;
    for(int i = 0 ; i < n ; i++) for(int j = 0 ; j < n ; j++) {
        int d; cin >> d;
        vec[i][j] = d;
        if(d==2) birus.push_back({0,i,j});
        if(d==1) emp--;
        if(d==0) t++;
    }
    if(!t){
        cout << 0;
        return 0;
    }
    visited.resize(birus.size(),0);
    active_birus.resize(m);
    
    active(0, 0, vec);
    cout << (res==INT_MAX?-1:res+1);
}