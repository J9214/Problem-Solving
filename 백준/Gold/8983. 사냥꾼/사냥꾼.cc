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

    ll m, n, l; cin >> m >> n>> l;
    vll gun(m);
    vpll ani(n);
    for(int i = 0 ; i < m ; i++) cin >> gun[i];
    for(int i = 0 ; i < n ; i++) {
        int a,b;cin >> a >> b;
        ani[i] = {a,b};
    }

    sort(gun.begin(),gun.end());
    sort(ani.begin(),ani.end());

    int res =0;
    for(int i = 0 ; i < ani.size(); i++){
        if(ani[i].Y>l) continue;

        ll le=0,ri=gun.size()-1;
        
        bool bOk=false;

        while(le <= ri){
            ll mid = (le+ri)/2;

            if(abs(gun[mid]-ani[i].X)+ani[i].Y <= l){
                bOk=true;
                break;
            }
            else{
                if(ani[i].X < gun[mid]){
                    ri = mid-1;
                }
                else le = mid+1;
            }
        }

        res += bOk;
    }    
    cout << res;

}