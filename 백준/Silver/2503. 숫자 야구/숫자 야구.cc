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

    int n; cin >> n;
    vector<string> vec(n);
    vector<point> cnt(n);
    for(int i = 0 ; i < n ; i++)
        cin >> vec[i] >> cnt[i].x >> cnt[i].y;
    
    int res = 0;
    for(int i = 100; i < 1000; i++){
        string s = to_string(i);
        if(find(s.begin(),s.end(),'0')!=s.end()) continue;
        if(s[0]==s[1]||s[0]==s[2]||s[1]==s[2]) continue;
        
        int f = 1;
        for(int j = 0 ; j < n ; j++){
            if(!f) break;
            int a=0,b=0;
            for(int k = 0 ; k < 3; k++){
                if(vec[j][k] == s[k]) a++;
                else if(vec[j][k] == s[(k+1)%3] || vec[j][k] == s[(k+2)%3]) b++;
            }
            if(cnt[j].x!=a||cnt[j].y!=b) f=0;
        }
        if(f) res++;
    }
    cout << res;
}