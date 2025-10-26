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

vi idx(4,0);
int n,k;
void func_right(vector<string> &vec, int num, int spin){
    if(num<4){
        int prev_idx = num - 1;
        int prev_pole = vec[prev_idx][(idx[prev_idx]+2)%8];
        int curr_pole = vec[num][(idx[num]+6)%8];

        if(prev_pole != curr_pole){
			func_right(vec, num+1, -spin);
			idx[num] = (idx[num]-spin+8)%8;
		} 
    }
}

void func_left(vector<string> &vec, int num, int spin){
    if(num>=0){
        int prev_idx = num + 1;
        int prev_pole = vec[prev_idx][(idx[prev_idx]+6)%8];
        int curr_pole = vec[num][(idx[num]+2)%8];

        if(prev_pole != curr_pole) {
            func_left(vec, num-1, -spin);
            idx[num] = (idx[num]-spin+8)%8;
		}
    }
}

int main(){
    FASTIO

    vector<string> vec(4); 
    for(int i = 0 ; i < 4 ; i++)
        cin >> vec[i];
    
    int m; cin >> m;
    while(m--){
        cin >> n >> k;
        func_right(vec, n, -k);
        func_left(vec, n-2, -k);
        idx[n-1] = (idx[n-1]-k+8)%8;
    }

    int res=0;
    for(int i = 0 ; i < 4; i++){
        res+=vec[i][idx[i]]=='1'?(1<<i):0;
    }

    cout << res;
}