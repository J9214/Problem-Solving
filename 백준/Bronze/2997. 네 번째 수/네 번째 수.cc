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

    vi vec(3);
    for(int i = 0 ; i < 3; i ++)cin >> vec[i];
    sort(vec.begin(), vec.end());
    if(vec[2]-vec[1]==vec[1]-vec[0])cout << vec[2]+vec[1]-vec[0];
    else if(vec[2]-vec[1]>vec[1]-vec[0])cout << vec[2]-vec[1]+vec[0];\
    else cout << vec[0]+vec[2]-vec[1];
}