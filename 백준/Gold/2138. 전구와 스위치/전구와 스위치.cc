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

char bit_rev(char c){
    return c == '0' ? '1' : '0';
}
int main(){
    FASTIO
    
    // 현재상태는 현재 idx와 다음 idx로만 결정 됨
    // 다음 상태는 현재 idx와 다음 idx, 다다음 idx로 결정 됨
    // 고려해야할 조건은 
    int n; cin >> n;
    string str, s; cin >> str >> s;
    string t=str;
    int res = 0;
    for(int i =1 ;  i < n ; i++){
        if(s[i-1]!=t[i-1]) {
            t[i-1]=bit_rev(t[i-1]);
            t[i]=bit_rev(t[i]);
            if(i<n-1) t[i+1]=bit_rev(t[i+1]);
            res++;
        }
    }
    if(t==s) {cout << res; return 0;}
    
    res=1;
    t=str;
    t[0]=bit_rev(t[0]);
    t[1]=bit_rev(t[1]);
    for(int i =1 ;  i < n ; i++){
        if(s[i-1]!=t[i-1]) {
            t[i-1]=bit_rev(t[i-1]);
            t[i]=bit_rev(t[i]);
            if(i<n-1) t[i+1]=bit_rev(t[i+1]);
            res++;
        }
    }
    if(t==s) {cout << res; return 0;}

    cout << -1;
}