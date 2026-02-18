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
    vi vec(n), seq(n);
    for(int i = 1 ; i <= n ; i++) vec[i-1]=i;
    for(auto &i : seq) cin >> i;

    do{
        bool b = 1;
        for(int i = 0 ; i < n ; i++){
            int c=0;
            for(int j = i-1; j >=0; j--){
                if(vec[j] > vec[i]) c++;
            }
            if(seq[vec[i]-1] != c) {b=0; break;}
        }
        if(b) break;
    }while(next_permutation(vec.begin(),vec.end()));
    print(vec);
}