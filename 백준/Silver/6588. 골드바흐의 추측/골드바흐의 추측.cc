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

    vi vec(1000001, 0);
    vi sosu;
    for(int i = 2 ; i < vec.size(); i++){
        if(vec[i]) continue;
        sosu.push_back(i);
        for(int j = i + i; j < vec.size(); j+=i){
            vec[j] = 1;
        }
    }

    int n; 
    while(cin >> n){
        if(!n) break;
        for(auto s : sosu){
            if(!vec[n-s]){
                cout << n << " = " << s << " + " << n-s << '\n';
                break;
            }
        }
    }

}