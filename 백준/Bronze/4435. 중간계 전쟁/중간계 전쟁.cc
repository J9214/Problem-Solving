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
#define X first
#define Y second
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}
#define modulo 1000000007

int main(){
    FASTIO

    int a; cin >> a;
    for(int t = 1; t <=a; t++){
        vi v1 = {1,2,3,3,4,10}, v2 = {1,2,2,2,3,5,10};
        int r1=0,r2=0,d;
        for(int i= 0 ; i<6; i ++){
            cin >> d;
            r1+=d*v1[i];
        }
        for(int i= 0 ; i<7; i ++){
            cin >> d;
            r2+=d*v2[i];
        }
        if(r1>r2) cout << "Battle "<<t<<": Good triumphs over Evil";
        else if(r1<r2) cout << "Battle "<<t<<": Evil eradicates all trace of Good";
        else cout << "Battle "<<t<<": No victor on this battle field";    
        cout << '\n';
    }   
    
}