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
    
    ll n; cin >> n ;
    vll vec(3);
    vec[0]=0;
    vec[1]=vec[2]=1;
    for(int i = 3 ; i <= n; i++)
        vec[i%3]=(vec[(i+1)%3]+vec[(i+2)%3])%modulo;
        
    cout << vec[n%3];
}