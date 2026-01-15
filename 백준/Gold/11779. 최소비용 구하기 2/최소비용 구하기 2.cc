#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<pi>> vvpi;
typedef vector<vector<ll>> vvll;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<ll, ll>> vpll;
typedef struct Point {int x, y;} point;
point direction[4] = {{1,0},{0,1},{-1,0},{0,-1}};
#define modulo 1000000007
void print(vi vec){for(auto i : vec) cout << i << ' ';}

int main(){
    FASTIO

    int n,m; cin >> n >> m;
    int a,b,c; 
    vvpi vec(n+1);
    vi dist(n+1, -1);
    vi prev(n+1, 0);

    while(m--){
        cin >> a>>b>>c;

        vec[a].push_back({b,c});
    }

    cin >> a >> b;

    priority_queue<pi, vpi, greater<pi>> pq;
    pq.push({0,a});
    dist[a] = 0;

    while(!pq.empty()){
        int curr = pq.top().second;
        int currdist = pq.top().first;
        pq.pop();

        if(currdist > dist[curr]) continue;
        for(int i = 0 ; i < vec[curr].size(); i++){
            int next = vec[curr][i].first;
            int nextdist = currdist + vec[curr][i].second;
            if(dist[next] == -1 || dist[next] > nextdist){
                dist[next] = nextdist;
                prev[next] = curr;
                pq.push({nextdist,next});
            }
        }
    }
    
    vi res;
    int t=b;
    while(b){
        res.push_back(b);
        b=prev[b];
    }


    cout << dist[t] <<'\n';
    cout << res.size() <<'\n';
    for(int i = res.size()-1; i>=0;i--){
        cout << res[i] << ' ' ;
    }
    
}