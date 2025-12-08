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
    vll vec(n);
    for(auto &i :vec) cin >> i;

    sort(vec.begin(),vec.end());
    
    ll res = 0;
    for(int i = 0 ; i < n ; i++){
        ll j = i+1, k = n-1;
        while(j<k){
            ll  t = vec[i] + vec[j] + vec[k];
            if(t == 0) {
                if(vec[j]==vec[k]) {
                    res += (k-j+1) * (k-j) / 2;
                    break;
                }
                int l=1,r=1;
                while(j+1<k && vec[j]==vec[j+1]) l++,j++;
                while(j<k-1 && vec[k]==vec[k-1]) r++,k--;
                
                res += l*r; 
                j++; 
                k--;
            }
            else if (t < 0) j++;
            else k--; 
        }
    }
    cout << res;
}