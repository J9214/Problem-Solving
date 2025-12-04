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

    string str, t, s=""; cin >> str >> t;
    int idx=0;
    for(auto i : str){
        if(idx>=s.size()) s.push_back(i), idx++;
        else s[idx++] = i;

        bool b = 1;
        for(int j = 0; j < t.size() ; j++)
            if(s[idx-1-j]!=t[t.size()-1-j]) {b=0; break;}

        if(b) idx -= t.size();
    }

    if(idx) cout << s.substr(0,idx);
    else cout << "FRULA";
}