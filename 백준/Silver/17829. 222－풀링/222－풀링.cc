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


vvi vec;
vi c_v(4);
int choose(int &a, int &b, int &c, int &d){
    c_v = {a,b,c,d};
    sort(c_v.begin(),c_v.end());

    return c_v[2];
}

int func(int x, int y, int diff){
    if(diff == 1) return vec[x][y];
    
    diff /= 2;

    int a = func(x,y,diff);
    int b = func(x,y+diff,diff);
    int c = func(x+diff,y,diff);
    int d = func(x+diff,y+diff,diff);

    return choose(a,b,c,d);
}

int main(){
    FASTIO

    int n; cin >> n;
    vec.resize(n,vi(n));
    for(auto &i : vec) for(auto &j : i) cin >> j;

    cout << func(0,0,n);
}