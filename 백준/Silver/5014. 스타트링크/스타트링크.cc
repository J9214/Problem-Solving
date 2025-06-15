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

#define X first
#define Y second
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}
#define modulo 1000000007

int main(){
    FASTIO

    int f, s, g, u ,d; cin >> f>> s>> g>> u >>d;
    vi vec(f,-1);
    queue<int> q;
    q.push(s-1);
    vec[s-1] = 0;
    vi direction = {u,-d};

    while(q.size()){
        auto x = q.front(); q.pop();

        for(auto dir:direction){
            int nx = x + dir;

            if(nx<0||nx>=f||vec[nx]>-1) continue;

            vec[nx] = vec[x]+1;
            q.push(nx);
        }
    }

    if(vec[g-1]==-1) cout << "use the stairs";
    else cout << vec[g-1];
}