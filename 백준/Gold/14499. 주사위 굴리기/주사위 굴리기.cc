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
point direction[4] = {{1,0},{-1,0},{0,-1},{0,1}};
#define modulo 1000000007
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}

void roll(vi &vec, int dir){
    int t=vec[0], b=vec[1], n=vec[2], s=vec[3], e=vec[4], w=vec[5];
    switch(dir){
        case 3: // north
            vec={s,n,t,b,e,w}; break;
        case 4: // south
            vec={n,s,b,t,e,w}; break;
        case 1: // east
            vec={w,e,n,s,t,b}; break;
        case 2: // west
            vec={e,w,n,s,b,t}; break;
        default: 
            break;
    }
}
int main(){
    FASTIO
    
    int n,m,x,y,t; cin >> n >> m >> x >> y >> t;
    vvi vec(n, vi(m,0));
    vi dice = {0,0,0,0,0,0};
    for(auto &i : vec) for(auto &j : i) cin >> j;
    while(t--){
        int a; cin >> a;
        
        int nx=x+direction[a-1].y;
        int ny=y+direction[a-1].x;

        if(nx<0||ny<0||nx>=n||ny>=m) continue;

        x = nx;
        y = ny;

        roll(dice, a);

        if(!vec[x][y]) 
            vec[x][y] = dice[1];
        else {
            dice[1] = vec[x][y];
            vec[x][y] = 0;
        }

        cout << dice[0] << '\n';
    }
}