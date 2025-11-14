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

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int p1=0,p2=0;
        while(n--){
            char c1,c2; cin >> c1 >> c2;
            if(c1=='R'){
                if(c2=='S') p1++;
                if(c2=='P') p2++;
            }
            else if(c1=='S'){
                if(c2=='R') p2++;
                if(c2=='P') p1++;
            }
            else if(c1=='P'){
                if(c2=='R') p1++;
                if(c2=='S') p2++;
            }
        }
        cout << (p1==p2 ? "TIE" : p1>p2?"Player 1" : "Player 2"); 
        cout << '\n';
    }
}