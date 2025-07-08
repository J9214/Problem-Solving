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
        int x1,y1,x2,y2,n; cin >> x1  >> y1>>x2>>y2>>n;
        int a=0,b=0;
        while(n--){
            int q,w,e; cin >> q >> w >> e;
            if(((q-x1) * (q-x1) + (w-y1) * (w-y1) <= e * e) && ((q-x2) * (q-x2) + (w-y2) * (w-y2) <= e * e)) continue;
            if((q-x1) * (q-x1) + (w-y1) * (w-y1) <= e * e) a++;
            if((q-x2) * (q-x2) + (w-y2) * (w-y2) <= e * e) b++;
        }
        cout << a+b << '\n';
    }
}