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

    ll n, m, s=0; cin >> n>> m;
    vll vec(n);
    for(auto &i : vec){
        cin >> i;
        s+=i;
    }
    m%=s;
    while(1){
        bool f = 0;
        s=0;
        for(auto &i : vec){
            if(m>=i){
                m-=i;
                s+=i;
                f=1;
            }
        }
        if(!f) break;
        m%=s;
    }
    cout << m;
}