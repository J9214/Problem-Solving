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

int main(){
    FASTIO

    int n, k; cin >> n >> k;
    vvi vec(2, vi(n));
    vvi visit(2, vi(n,0));
    vpi direction = {{0,1},{0,-1},{1,k}};
    for(int j = 0 ; j < 2; j++)
        for(int i = 0 ; i < n ; i ++){
            char c; cin >> c;
            vec[j][i] = c-'0';
            if(vec[j][i]) visit[j][i] = 1;
        }   
                
    queue<point> q;
    q.push({0,0});
    
    int d = 0, cnt=1, n_cnt=0;
    // n_cnt : d+1날짜에 방문할 곳 개수
    // cnt : d 날짜에 방문할 곳 개수
    // cnt == 0 이면  d 열을 0으로 만들고 접근 불가능하게
    // 그리고 cnt = n_cnt; n_cnt = 0;
    while(q.size()){
        auto [x,y] = q.front(); q.pop();
        visit[x][y] = 0;
        for(auto i : direction){
            int nx = (x+i.X)%2;
            int ny = y+i.Y;
            if(ny>=n) {cout << 1; exit(0);}
            
            if(nx<0||ny<0||nx>=2||ny>=n||!vec[nx][ny]||!vec[x][y]||!visit[nx][ny]) continue;
            q.push({nx,ny});
            visit[nx][ny] = 0;
            n_cnt++;
        }
        cnt--; 
        if(cnt == 0){
            if(d>=0) vec[0][d] = vec[1][d] = 0;
            d++;
            cnt = n_cnt; 
            n_cnt = 0;
        }
    }
    cout<<0;
}