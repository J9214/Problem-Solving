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

ll pibo(ll a){
    if(a==1) return 1;
    return a + pibo(a-1);
}
int main(){
    FASTIO

    int t; cin >> t;
    vll vec(68);
    vec[0]=1;
    vec[1]=1;
    vec[2]=2;
    vec[3]=4;
    vec[4]=8;
    ll d=8;
    for(int i=5;i<68;i++){
        d+=vec[i-1];
        d-=vec[i-5];
        vec[i]=d;
    }
    while(t--){
        ll n; cin >> n;
        cout << vec[n] << '\n';
    }
}