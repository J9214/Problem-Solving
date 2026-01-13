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
void print(vll vec){for(auto i : vec) cout << i << ' ';}

int main(){
    FASTIO

    ll n, t=1; cin >> n;
    if(n==0) {cout << "NO"; return 0;}
    vll vec;
    vec.push_back(1);
    for(int i = 1; t < 1000000000000000000; i++, t*=i)
        vec.push_back(t);

    for(int i = vec.size()-1 ; i>=0; i--)
        n-= (n>=vec[i]) * vec[i];
    
    cout << (n?"NO":"YES");
}