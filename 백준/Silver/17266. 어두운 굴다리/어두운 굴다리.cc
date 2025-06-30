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
    
    int n,m; cin >> n>> m;
    vi vec(m);
    for(int i = 0 ; i < m ; i++) cin >> vec[i];

    int l=1,h=n;
    while(l<h){
        int mid = (l+h)/2;
        int r_t=0;
        bool f=0;
        for(auto i:vec){
            if(i-mid>r_t){f=1;break;}
            r_t = i+mid;
        }
        if(f||r_t<n)l=mid+1;
        else h=mid;
    }
    cout << h;
}