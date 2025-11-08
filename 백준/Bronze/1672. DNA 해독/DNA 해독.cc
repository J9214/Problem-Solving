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

    unordered_map<string, char> mp;

    mp["AA"]='A';
    mp["AG"]='C';
    mp["AC"]='A';
    mp["AT"]='G';
    mp["GA"]='C';
    mp["GG"]='G';
    mp["GC"]='T';
    mp["GT"]='A';
    mp["CA"]='A';
    mp["CG"]='T';
    mp["CC"]='C';
    mp["CT"]='G';
    mp["TA"]='G';
    mp["TG"]='A';
    mp["TC"]='G';
    mp["TT"]='T';

    int n; cin >> n;
    string s; cin >> s;
    int idx = n-1;
    while(idx--){
        string str{s[idx],s[idx+1]};
        s[idx] = mp[str];
    }

    cout << s[0];
}