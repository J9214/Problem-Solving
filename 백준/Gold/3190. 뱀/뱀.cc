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
point direction[4] = {{0,1},{1,0},{0,-1},{-1,0}};
#define modulo 1000000007
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}

int n,k,l;
vvi vec;
int d=0;

deque<pi> snake;
bool move(){
    auto [x,y] = snake.front();

    int nx = x+direction[d].x;
    int ny = y+direction[d].y;

    // 벽이나 자기 몸
    if(vec[nx][ny]==-1) return 0;

    snake.push_front({nx,ny});

    // 앞에 사과가 아니면 뒤에 뺌
    if(vec[nx][ny]!=9){
        int tx = snake.back().first;
        int ty = snake.back().second;
        vec[tx][ty] = 0;
        snake.pop_back();
    }
    vec[nx][ny] = -1;

    return 1;
}
int main(){
    FASTIO
    
    cin >> n >> k;
    vec.assign(n+2,vi(n+2,0));
    // 맵 만들기
    for(int i = 0 ; i < n+2 ; i++)
        vec[i][0]=vec[0][i]=vec[i][n+1]=vec[n+1][i]=-1;
    
    while(k--){
        int a,b;cin >> a >> b;
        vec[a][b] = 9;
    }

    cin >> l;
    vector<pair<int,char>> turn(l);
    int turn_idx=0;
    for(auto &i:turn) cin >> i.first >> i.second;

    snake.push_back({1,1});
    vec[1][1] = -1;

    int sec=0;
    while(++sec){     
        if(!move()) break;

        if(turn[turn_idx].first==sec){
            if(turn[turn_idx].second == 'D')
                d=(d+5)%4;
            else d=(d+3)%4;
            turn_idx++;
        }
    }

    cout << sec;
}