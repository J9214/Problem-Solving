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

int main(){
    FASTIO

    int n ; cin >> n;
    string s; cin >> s;
    bool r=0,b=0;
    int rc=0,bc=0,res=0; 
    for(auto i : s){
        if(i=='B')b=1;
        else r=1;
        if(b&&i=='R') rc++;
        if(r&&i=='B') bc++;
    }
    res = min(rc,bc);
    b=r=rc=bc=0;
    for(int i = n-1; i >= 0; i--){
        if(s[i]=='B')b=1;
        else r=1;
        if(b&&s[i]=='R') rc++;
        if(r&&s[i]=='B') bc++;
    }
    res = min({rc,bc,res});
    cout << res;
}