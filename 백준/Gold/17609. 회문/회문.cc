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

bool IsPalindrome(string &s, int i, int j){
    while(i<j)
        if(s[i++]!=s[j--]) return 0;
    return 1;
}

int IsPseudoPalindrome(string &s){
    int i=0, j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j]){
            if(IsPalindrome(s,i+1,j)) return 1;
            if(IsPalindrome(s,i,j-1)) return 1;
            return 2;
        }
        i++;
        j--;        
    }
    return 0;
}
int main(){
    FASTIO

    int n; cin >> n;
    while(n--){
        string s; cin >> s;
        cout << IsPseudoPalindrome(s) << '\n';
    }
}