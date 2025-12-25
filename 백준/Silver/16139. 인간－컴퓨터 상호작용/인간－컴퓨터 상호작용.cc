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

    string s;cin >> s;
    int n; cin >> n;
    vvi vec(s.size()+1,vi(26,0));

    for(int i = 1 ; i<= s.size(); i++){
        vec[i] = vec[i-1];
        vec[i][s[i-1]-'a']++;
    }

    while(n--){
        char c; int a,b; cin >> c >> a >> b;
        cout << vec[b+1][c-'a'] - vec[a][c-'a'] << '\n';
    }
}