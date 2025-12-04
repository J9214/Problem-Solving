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

string mult(int n){
    vector<int> vec(50,0);
    vec[0] = 1;
    for(int i = 0 ; i < n ; i ++){
        for(auto &j : vec) j*=3;
        for(int j = 0 ; j < 49; j++) {
            vec[j+1] += vec[j]/10;
            vec[j]%=10;
        }
    }  
    
    string s="";
    bool b=0;
    for(int i = 49; i--;){
        if(vec[i])b=1;
        if(b) s+=to_string(vec[i]);
    }

    return s;
}
int main(){
    FASTIO

    unsigned long long t;
    while(cin >> t){
        if(!t) break;
        cout << "{ ";
        bool b=0;
        t--;
        for(int i=0; t; i++, t>>=1){
            if(t&1){
                cout << (b?", ":"")<< mult(i);
                b=1;
            }
        }
        cout << (b?" ":"") << "}\n";
    }
}