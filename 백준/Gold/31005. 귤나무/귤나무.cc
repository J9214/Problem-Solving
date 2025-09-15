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
    list<ll> ls;
    for(int i = 0 ; i < n; i++){
        ll d; cin >> d;
        ls.push_back(d);
        s+=d;
    }
    m%=s;
    while(1){
        if(ls.empty()) break;
        for (auto it = ls.begin(); it != ls.end(); ) {
            if (*it > m) {
                s -= *it;
                it = ls.erase(it); 
            }
            else {
                m -= *it;          
                ++it;
            }
        }  
        if(s)m%=s;
    }
    cout << m;
}