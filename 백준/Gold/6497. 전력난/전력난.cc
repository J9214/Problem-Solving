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

int disjoint(int x, vi &uf){
    return (x != uf[x]) ? uf[x] = disjoint(uf[x], uf) : x;
}

struct node{
    int a,b,c;
    bool operator<(const node& other) const {
        return a > other.a;
    }
};

int main(){
    FASTIO
    
    while(1){
        int n,m; cin >> n >> m;
        if(!n&&!m) break;

        int total = 0;
        vi vec(n);
        for(int i = 0 ; i < vec.size() ; i++) vec[i]=i;

        priority_queue<node> pq;
        while(m--){
            int a,b,c; cin >> a >> b >> c;
            pq.push({c,a,b});
            total += c;
        }  

        int cost = 0;

        while(pq.size()){
            auto [c,a,b] = pq.top(); pq.pop();
            
            int x=disjoint(a,vec);
            int y=disjoint(b,vec);

            if(x!=y){
                vec[x] = y;
                cost += c;
            }
        }

        cout << total - cost<<'\n';
    }

}