#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(i,n) for(int i = 1 ; i <= n ; i++)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define INF 99999999

int main(){
    FASTIO

    int n, m,i,j,k,res = INF; cin >> n >> m;
    vvi vec(401,vi(401,INF));

    while(m--){
        int a,b,c; cin >> a >> b >> c;
        vec[a][b]=c;
    }

    l(i,n)l(j,n)l(k,n) vec[j][k] = min(vec[j][k], vec[j][i] + vec[i][k]);
    l(i,n) res = min(res,vec[i][i]);

    if(res == INF) cout << -1;
    else cout << res;
}