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

int n, m; 
int res = 0;

vvi enemy, frnd;
vi team;
queue<int> q;

void func(int idx){
    team[idx] = 1;
    
    for(auto j : frnd[idx]) {
        if(team[j]) continue;
        q.push(j);
        team[j] = 1;
    }

    for(auto j : enemy[idx]){
        for(auto k : enemy[j]) {
            if(team[k]) continue;
            q.push(k);
            team[k] = 1;
        }   
    }

    while(q.size()){
        int curr = q.front(); q.pop();
        func(curr);
    }
}

int main(){
    FASTIO
    
    cin >> n >> m;
    enemy.resize(n+1);
    frnd.resize(n+1);
    team.assign(n+1,0);

    while(m--){
        char c; int a,b;
        cin >> c >> a >> b;
        team[a]=team[b]=0;
        if(c=='E'){
            enemy[a].push_back(b);
            enemy[b].push_back(a);
        }
        else {
            frnd[a].push_back(b);
            frnd[b].push_back(a);
        }
    }
    
    for(int i = 1 ; i <= n; i++){
        if(team[i]) continue;
        func(i);
        res++;
    }
    
    cout << res;
}