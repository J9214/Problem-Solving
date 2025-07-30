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

int main(){
    FASTIO
    
    ll a,b;cin >> a >> b;
    vll vec(b-a+1,0);
    for(ll i = 2; i*i <= b; ++i){ // 제곱
        ll sq = i*i;
        ll s = (a+sq-1)/sq*sq;
        for(ll j = s; j <= b; j+=sq){ // 인덱스
            vec[j-a]=1;
        }
    }
    ll res=0;
    for(ll i = 0; i < vec.size();i++){
        if(!vec[i]) res++;
    }
    cout <<res;
}