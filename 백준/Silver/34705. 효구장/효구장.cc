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

int n,a,b;
vll v;
bool t = 0;
void func(int idx, ll s){
    if(t) return;
    if(a<=s&&s<=b) {t=1;return;}
    
    for(int i = idx+1 ; i < 5; i++)
        func(i,s+v[i]);
}
int main(){
    FASTIO

    long long res = 0;
    cin >> n;
    v.resize(5);
    
    while(n--){
        t=0;
        cin>>a>>b;
        for(auto &i:v)cin>>i;
        func(-1,0);
        cout << (t?"YES":"NO") << '\n';
    }
    
}