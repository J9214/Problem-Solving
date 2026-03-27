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

int n, x,y;
int s;
vvi vec;
bool f=0;
void func(int num, int c, int cx, int cy){
    if(c==s*s-1) {
        print(vec);
        f=1;
        return;
    }
    for(int i = 0; i < s; i++){
        for(int j = 0; j < s; j ++){
            if(f||vec[i][j]) continue;
            for(int k = 0 ; k < 4 ; k++){
                int nx1 = i+direction[k].x;
                int nx2 = i+direction[(k+1)%4].x;
                int ny1 = j+direction[k].y;
                int ny2 = j+direction[(k+1)%4].y;
                if(nx1<0||nx2<0||ny1<0||ny2<0||nx1>=s||nx2>=s||ny1>=s||ny2>=s) continue;
                int b1 = vec[nx1][ny1];
                int b2 = vec[nx2][ny2];
                if(b1||b2) continue;
                vec[i][j] = vec[nx1][ny1] = vec[nx2][ny2] = num;
                func(num+1, c+3, i,j);
                vec[i][j] = vec[nx1][ny1] = vec[nx2][ny2] = 0;
            }
        }
    }
}
int main(){
    FASTIO
    
    cin >> n>>x>>y;
    s=(int)pow(2,n);
    vec.assign(s,vi(s,0));
    vec[s-y][x-1] = -1;

    func(1,0,0,0);
    
}