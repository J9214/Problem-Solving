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
    
    map<int,int> mp;
    int a,b,d; cin >> a >> b;
    for(int i = 0 ; i< a; i++){
        cin >> d;
        mp[d]++;
    }
    for(int i = 0 ; i< b; i++){
        cin >> d;
        mp[d]--;
        if(mp[d]<=0) mp.erase(d);
    }
    cout << mp.size() << '\n';
    for(auto i : mp)
        cout << i.first << ' ';
}