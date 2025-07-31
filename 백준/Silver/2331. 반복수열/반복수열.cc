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
    
    int a, p; cin >> a >> p;
    vi vec;
    vec.push_back(a);

    while(find(vec.begin(),vec.end(),a) -vec.begin() == abs(find(vec.rbegin(),vec.rend(),a) - vec.rbegin() - (int)vec.size()+1)){
        int t= 0;
        while(a){
            t+=pow(a%10,p);
            a/=10;
        }
        vec.push_back(t);
        a=t;
    }
    cout << find(vec.begin(),vec.end(),vec.back()) - vec.begin();
    
}