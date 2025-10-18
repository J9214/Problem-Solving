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

int res=0;
int n; 

void l_m(vvi vec, int d);
void r_m(vvi vec, int d);
void u_m(vvi vec, int d);
void d_m(vvi vec, int d);

void dfs(vvi vec, int d){
    if(d<5){
        l_m(vec, d);
        r_m(vec, d);
        u_m(vec, d);
        d_m(vec, d);
    }
}

void l_m(vvi vec, int d){
    for(int i = 0 ; i < n ; i++){
        int idx = 0, prev = -1;
        for(int j = 0 ; j < n; j++){
            if(vec[i][j] != 0){
                if(prev==-1) prev = j;
                else if(vec[i][j] != vec[i][prev]) {
                    int t = vec[i][prev];
                    vec[i][prev] = 0;
                    vec[i][idx] = t;
                    ++idx;
                    prev = j;
                }
                else {
                    int t = vec[i][prev];
                    vec[i][prev] = 0;
                    vec[i][j] = 0;
                    vec[i][idx] = t<<1;
                    res = max(vec[i][idx],res);
                    ++idx;
                    prev = -1;
                }
            }
        }
        if(prev != -1){
            int t = vec[i][prev];
            vec[i][prev] = 0;
            vec[i][idx] = t;
        }
    }

    dfs(vec, d+1);
}

void r_m(vvi vec, int d){
    for(int i = 0 ; i < n ; i++){
        int idx = n-1, prev = -1;
        for(int j = n-1 ; j >= 0; j--){
            if(vec[i][j] != 0){
                if(prev==-1) prev = j;
                else if(vec[i][j] != vec[i][prev]) {
                    int t = vec[i][prev];
                    vec[i][prev] = 0;
                    vec[i][idx] = t;
                    --idx;
                    prev = j;
                }
                else {
                    int t = vec[i][prev];
                    vec[i][prev] = 0;
                    vec[i][j] = 0;
                    vec[i][idx] = t<<1;
                    res = max(vec[i][idx],res);
                    --idx;
                    prev = -1;
                }
            }
        }
        if(prev != -1){
            int t = vec[i][prev];
            vec[i][prev] = 0;
            vec[i][idx] = t;
        }
    }

    dfs(vec, d+1);
}

void d_m(vvi vec, int d){
    for(int i = 0 ; i < n ; i++){
        int idx = n-1, prev = -1;
        for(int j = n-1 ; j >= 0; j--){
            if(vec[j][i] != 0){
                if(prev==-1) prev = j;
                else if(vec[j][i] != vec[prev][i]) {
                    int t = vec[prev][i];
                    vec[prev][i] = 0;
                    vec[idx][i] = t;
                    --idx;
                    prev = j;
                }
                else {
                    int t = vec[prev][i];
                    vec[prev][i] = 0;
                    vec[j][i] = 0;
                    vec[idx][i] = t<<1;
                    res = max(vec[idx][i],res);
                    --idx;
                    prev = -1;
                }
            }
        }
        if(prev != -1){
            int t = vec[prev][i];
            vec[prev][i] = 0;
            vec[idx][i] = t;
        }
    }

    dfs(vec, d+1);
}

void u_m(vvi vec, int d){
    for(int i = 0 ; i < n ; i++){
        int idx = 0, prev = -1;
        for(int j = 0 ; j < n; j++){
            if(vec[j][i] != 0){
                if(prev==-1) prev = j;
                else if(vec[j][i] != vec[prev][i]) {
                    int t = vec[prev][i];
                    vec[prev][i] = 0;
                    vec[idx][i] = t;
                    ++idx;
                    prev = j;  
                }
                else {
                    int t = vec[prev][i];
                    vec[prev][i] = 0;
                    vec[j][i] = 0;
                    vec[idx][i] = t<<1;
                    res = max(vec[idx][i],res);
                    ++idx;
                    prev = -1;
                }
            }
        }
        if(prev != -1){
            int t = vec[prev][i];
            vec[prev][i] = 0;
            vec[idx][i] = t;
        }
    }

    dfs(vec, d+1);
}


int main(){
    FASTIO
    
    cin >> n;
    vvi vec(n,vi(n));
    for(auto &i:vec)for(auto &j:i) {
        cin >> j;
        res = max(res,j);
    }

    dfs(vec,0);

    cout << res;
}