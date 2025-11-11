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

struct land{
    int num;
    int x;
    int y;

    bool operator<(const land &d) const {
		return num < d.num;
	}

};
vvi vec; 
vvi visited;
vector<land> lands;
int n,m;
int total=0;
int year=0;
void melt(){
    year++;
    
    visited.assign(n,vi(m,0));
    
    for(auto &i : lands){
        for(auto dir : direction){
            int nx = i.x + dir.x;
            int ny = i.y + dir.y;
            
            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            if(vec[nx][ny]==0){
                i.num--;
            }
        }     
    }

    for(auto i:lands){
        vec[i.x][i.y] = max(i.num,0);
        if(i.num>0) visited[i.x][i.y] = 1;
    }

    sort(lands.rbegin(),lands.rend());
    while(lands.size() && lands.back().num <= 0) lands.pop_back();
}

bool bfs(){
    melt();
    total = lands.size();
    
    queue<pi> q;
    q.push({lands[0].x,lands[0].y});
    visited[lands[0].x][lands[0].y] = 0;
    int count = 1;

    while(q.size()){
        auto [x,y] = q.front(); q.pop();
    
        for(auto dir : direction){
            int nx = x + dir.x;
            int ny = y + dir.y;
            
            if(nx<0||ny<0||nx>=n||ny>=m||!visited[nx][ny]) continue;

            q.push({nx,ny});
            count++;
            visited[nx][ny] = 0;
        }     
    }
    return (count != total ? 1 : 0);
}
int main(){
    //FASTIO

    cin >> n >> m;
    vec.resize(n,vi(m));
    
    for(int i = 0;  i < n ; i++) for(int j = 0 ; j < m; j++){
        cin >> vec[i][j];
        if(vec[i][j]) lands.push_back({vec[i][j],i,j});
    }
    
    
    while(lands.size()){
        if(bfs()) break;
    }
    if(lands.size()) cout << year;
    else cout << 0;
}