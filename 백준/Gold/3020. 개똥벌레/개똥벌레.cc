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

    int n, m; cin >> n >> m;
    
    vi l,h;
    for(int i = 0 ;  i< n ; i++){
        int d; cin >> d;
        if(i%2) l.push_back(d);
        else h.push_back(d);
    }

    sort(l.begin(),l.end());
    sort(h.begin(),h.end());

    vi l_v(m,0),h_v(m,0);

    for(int i = 0 ; i < n/2; i++){
        if(!l_v[l[i]-1]) l_v[l[i]-1]=n/2-i;
        if(!h_v[m-h[i]]) h_v[m-h[i]]=n/2-i;
    }

    for(int i = m-2 ; i >= 0; i--)
        if(!l_v[i]&&l_v[i+1]) l_v[i] = l_v[i+1];
    for(int i = 1 ; i < m; i++)
        if(!h_v[i]&&h_v[i-1]) h_v[i] = h_v[i-1];
    
    for(int i = 0 ; i < m ; i++) l_v[i]+=h_v[i];    

    sort(l_v.begin(),l_v.end());

    cout << l_v[0] << ' ' << upper_bound(l_v.begin(),l_v.end(),l_v[0])-l_v.begin();
    
}