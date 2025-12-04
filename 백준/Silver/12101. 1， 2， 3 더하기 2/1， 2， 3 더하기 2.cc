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

string s="";
vector<string> vec;

void func(int d){
    if(d<=0){
        if(d==0)vec.push_back(s);
        return;
    }

    for(int i = 1; i <= 3; i++){
        s+=to_string(i);
        func(d-i);
        s.pop_back();
    }
}
int main(){
    FASTIO

    int n,k; cin >> n >> k;

    func(n);
    
    if(k > vec.size()) {cout  << -1; return 0;}
    for(int i = 0 ; i < vec[k-1].size(); i++)
        cout << (i?"+":"") << vec[k-1][i];
    
}