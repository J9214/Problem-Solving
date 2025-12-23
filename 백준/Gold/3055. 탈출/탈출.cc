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

int n,m; 
pi goal;
vvi mp;
struct V{
    int i;
    int j;
    int t;
};
queue<V> w,s;
int ti = 0;

void flood(){
    while(w.size()){
        auto [x,y,t] = w.front();
        if(t!=ti) break;
        w.pop();
        
        for(auto dir : direction){
            auto nx = x + dir.x;
            auto ny = y + dir.y;

            if(nx<0||ny<0||nx>=n||ny>=m||mp[nx][ny]<0||(nx==goal.first&&ny==goal.second)) continue;

            mp[nx][ny] = -1;
            w.push({nx,ny,t+1});
        }
    }
}

void move(){
    while(s.size()){
        auto [x,y,t] = s.front();
        if(t!=ti) break;
        s.pop();
        if(mp[x][y] < 0) continue;
        
        for(auto dir : direction){
            auto nx = x + dir.x;
            auto ny = y + dir.y;

            if(nx<0||ny<0||nx>=n||ny>=m||mp[nx][ny]) continue;

            mp[nx][ny] = mp[x][y]+1;
            s.push({nx,ny,t+1});
        }
    }
}
int main(){
    FASTIO

    cin >> n>> m;

    mp.resize(n,vi(m));
    for(int i = 0 ; i < n ; i++) for(int j = 0 ; j < m; j++) {
        char c; cin >>c;
        if(c=='*') {
            mp[i][j]=-1;
            w.push({i,j,0});
        }
        else if (c=='X') mp[i][j] = -2;
        else mp[i][j] = 0;

        if (c=='S') {s.push({i,j,0}); mp[i][j] =1;}
        else if(c=='D') goal = {i,j};
    }
    
    while(s.size()&&!mp[goal.first][goal.second]){
        move();
        flood();
        ti++;
    }

    if(mp[goal.first][goal.second]) cout << mp[goal.first][goal.second]-1;
    else cout << "KAKTUS";
}