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

int n;
vvi vec;

int res = 99999999;

void calc(int b){
    int t1 = 0;
    int t2 = 0;

    for(int i = 0 ; i < n; i++){
        for(int j = i+1 ; j < n ; j++){
            if((b & (1<<i)) && (b & (1<<j))){
                t1+=vec[i][j]+vec[j][i];
            }

            if(!(b & (1<<i)) && !(b & (1<<j))){
                t2+=vec[i][j]+vec[j][i];
            }
        }
    }

    res = min(res,abs(t1-t2));
}

void func(int t, int b, int idx){
    if(t==n/2) {
        calc(b);

        return;
    }

    for(int i = idx + 1; i <n; i++){
        func(t+1, b | (1<<i), i);
    }
}
int main(){
    FASTIO
    
    cin >> n;
    vec.resize(n,vi(n));

    for(auto &i:vec) for(auto &j : i) cin >> j;

    func(0,0,-1);

    cout << res;
}