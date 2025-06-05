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
typedef vector<vector<pair<int, int>>> vvpi;
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

    int n,m; cin >> n >> m;
    vvpi graph(n);
    vvi vec(n+1, vi(n+1, modulo));

    for(int i = 0; i <= n; i++)
        vec[i][i] = 0;
    while(m--){
        int a,b,c; cin >> a >> b >> c;
        vec[a][b] = min(vec[a][b],c);
    }

    for(int i = 1 ;  i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            for(int k = 1; k <= n ; k++){
                vec[j][k] = min(vec[j][k], vec[j][i] + vec[i][k]);
            }
        }
    }

    int t; cin >> t;
    vi fr(t);
    for(int i = 0 ; i < t ; i++) cin >> fr[i];

    vpi res;
    
    for(int i = 1 ; i <= n; i++){
        int t_res=0;
        for(auto j : fr) t_res = max(t_res,vec[i][j] + vec[j][i]);
        res.push_back({t_res,i});
    }
    sort(res.begin(),res.end());

    cout << res[0].Y;
    for(int i = 1 ; i < res.size(); i++){
        if(res[i-1].X != res[i].X) break;
        cout << ' ' << res[i].Y;
    }
}