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

int main(){
    //FASTIO
    
    int t; cin  >>t;
    while(t--){
        int n,m; cin >> n >> m;

        vi vec(n+1,0);
        vvi fluid(n+1,vi(n+1,99999999));;

        while(m--){
            int a,b,c;cin >> a >> b>>c;
            fluid[a][b]=fluid[b][a] = c;
        }

        for(int i =1 ; i <= n; i++) fluid[i][i] = 0;
        for(int i = 1; i <= n ; i++)
            for(int j = 1; j <= n ; j++)
                for(int k = 1; k <= n; k++)
                    fluid[j][k] = min(fluid[j][k], fluid[j][i] + fluid[i][k]);

        int f; cin >> f;
        vi fr(f);
        for(auto &i : fr) cin >> i;

        for(int i = 1; i <= n ; i++)
            for(int j : fr)
                vec[i] += fluid[j][i];

        int a=INT_MAX,b=0;
        for(int i = 1; i <=n; i++){
            if(vec[i] < a) a=vec[i], b=i;
        }

        cout << b << '\n';
    }
}