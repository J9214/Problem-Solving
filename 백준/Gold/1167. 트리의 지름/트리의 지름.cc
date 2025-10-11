#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<pi>> vvpi;
typedef vector<pair<int, int>> vpi;

void print(vi vec){for(auto i : vec) cout << i << ' ';}
vi visited(100001,0);
int node=1;
int length=0;

void func(int idx, vvpi &vec, int l){
    visited[idx] = 1;
    if(l > length) node = idx, length = l;
    for(int i = 0 ; i < vec[idx].size() ; i++){
        int next = vec[idx][i].first;
        if(visited[next]) continue;
        func(next, vec, l + vec[idx][i].second);
    }
    
}
int main(){
    FASTIO

    int n; cin >> n;
    vvpi vec(n+1);
    while(n--){
        int a,b; cin >> a;
        while(cin >> b){
            if(b==-1) break;
            int c; cin >> c;
            vec[a].push_back({b,c});
        }
    }

    func(1,vec,0);
    fill(visited.begin(), visited.end(), 0); 
    func(node,vec,0);
    cout << length;
}