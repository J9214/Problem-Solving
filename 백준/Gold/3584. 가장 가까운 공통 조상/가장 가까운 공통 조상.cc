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

vvi vec;

int check(vi &rank, int num){
    int d;
    if(vec[num].empty()) d=0;
    else if(rank[vec[num][0]]) d = rank[vec[num][0]];
    else d = check(rank, vec[num][0]);

    return (rank[num] = 1 + d);
}

int main(){
    FASTIO
 
    int t;  cin >> t;
    while(t--){
        int n; cin >> n;

        vec.clear();
        vec.resize(n+1);
        vi rank(n+1,0);
        for(int i = 1 ; i < n; i++){
            int a,b; cin >> a >> b;

            vec[b].push_back(a);
        }

        for(int i = 1; i <= n ; i++){
            if(!rank[i]) check(rank, i);
        }

        int a,b; cin >> a >> b;

        while(a!=b){
            if(rank[a]<rank[b]) b=vec[b][0];
            else a=vec[a][0];
        }

        cout << a << '\n';
    }


}