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

int n,m,k,res;
vvi vec;
void func(int x, int y, int d){
    if(x==0&&y==m-1&&d==k) {res++; return;}
    if(d>=k) return;
    vec[x][y] = -1;

    for(auto dir : direction){
        int nx = x + dir.x;
        int ny = y + dir.y;

        if(nx<0||ny<0||nx>=n||ny>=m||vec[nx][ny]==-1) continue;
        
        func(nx,ny,d+1);
    }
    vec[x][y]=0;
}
int main(){
    FASTIO

    cin >> n >> m >> k;
    vec.resize(n,vi(m));
    for(auto &i : vec) for(auto &j:i){
        char d; cin >> d;
        if(d=='.') j=0;
        else j=-1;
    }

    func(n-1,0,1);

    cout << res;
}   