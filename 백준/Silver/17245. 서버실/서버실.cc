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
void print(vll vec){for(auto i : vec) cout << i << ' ';}
void print(vpi vec){for(auto i : vec) cout << i.first << ' ' << i.second << '\n';}

int main(){
    FASTIO
    
    ll n; cin >> n;
    ll total=0;
    map<int,int> mp;

    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++){
            int d;cin >>d;
            mp[d]++;
            total += d;
        }
    
    int com=n*n;
    int prev = 0;

    ll need = (total + 1) / 2;

    for (auto &[h, cnt] : mp) {
        ll len = h - prev;         
        ll can_add = len * com;    

        if (need <= can_add) {        
            ll delta = (need + com - 1) / com; 
            cout << prev + delta;
            return 0;
        }

        need -= can_add;  
        com -= cnt;       
        prev = h;
    }
}