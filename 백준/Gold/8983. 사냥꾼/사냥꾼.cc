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

    int m, n, l; cin >> m >> n>> l;
    vi gun(m);
    vpi ani(n);
    vi isDead(n,0);
    for(int i = 0 ; i < m ; i++) cin >> gun[i];
    for(int i = 0 ; i < n ; i++) {
        int a,b;cin >> a >> b;
        ani[i] = {a,b};
    }

    sort(gun.begin(),gun.end());
    sort(ani.begin(),ani.end());

    int i=0,j=0,res=0;
    while(i<n||j<m){        
        if(i<n&&j<m&&abs(gun[j]-ani[i].X)+ani[i].Y <= l) {
            res++;
            i++;
        }
        else if(j<m&&gun[j]<ani[i].X) j++;// 삼각형 오른쪽으로 벗어날 때는 i++;
        else if(i<n)i++;
        else j++;
        
    }
    cout << res;
}