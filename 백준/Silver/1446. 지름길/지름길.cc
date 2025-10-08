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

struct inf{int s,e,l;};

int main(){
    FASTIO

    int n,m; cin >> n >> m;
    vi vec(m+1);
    vector<inf> road(n);
    for(int i = 0 ; i < n ; i++){
        int a,b,c;cin >> a >> b >> c;
        road[i]={a,b,c};
    }
    sort(road.begin(),road.end(),[](inf &a, inf &b){
        return a.e<b.e;
    });

    int j = 0;
    vec[0] = 0;
    for(int i = 1 ; i <= m ; i++){
        vec[i] = vec[i-1]+1;
        while(j<n&&road[j].e==i) vec[i] = min(vec[i], vec[road[j].s] + road[j].l), j++;
    }
    cout << vec[m];
}   