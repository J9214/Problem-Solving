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

    ll n; cin >> n;
    
    if(n==1){
        unsigned long long a,b; cin >> a >> b;
        a+=b;
        const string hex = "0123456789abcdef";
        string s="aaaaaaaaaaaaa";

        for (int i = 12; i >= 0 && a > 0; --i) {
            s[i] = 'a' + a % 26;
            a /= 26;
        }

        cout << s;
    }
    else {
        string s; cin >> s;

        unsigned long long val = 0;
        for (char c : s) {
            val = val*26 + (c - 'a');
        }
        
        cout << val;
    }
}