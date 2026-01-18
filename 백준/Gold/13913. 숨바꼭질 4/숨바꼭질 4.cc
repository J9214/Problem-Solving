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

vi parent(200001,-1);
vi vec(200001,-1);
int n,m;

void func(){    
    priority_queue<pi, vpi, greater<pi>> pq;
    vec[n] = 0;
    pq.push({0,n});

    while(pq.size()){
        auto [d,c] = pq.top(); pq.pop();
        if(c==m) break;

        if(d>vec[c]) continue;
        int nd = d+1;
        
        for(int p : {c-1, c+1, c*2}){
            if(p<0||p>200000||vec[p]>=0) continue;
            
            vec[p] = nd;
            parent[p] = c;
            pq.push({nd, p});
        }
       
    }
    
}
int main(){
    FASTIO
    
    cin >> n >> m;
    
    vi res;
    
    func();

    int t=m;
    while(t>=0){
        res.push_back(t);
        t = parent[t];
    }

    if(n==m) cout << 0;
    else cout << vec[m];
    cout << '\n';
    for(int i = res.size()-1; i >= 0; i--)
        cout << res[i] << ' ';
    
}