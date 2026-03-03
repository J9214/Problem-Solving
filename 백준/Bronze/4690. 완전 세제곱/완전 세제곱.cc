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
    FASTIO

    map<int,int> mp;
    for(int i = 1; i <= 100; i++)
        mp[i*i*i]=1;

    for(int l = 1 ; l <= 100; l++)
        for(int i = 2 ; i <= 100; i++)
            for(int j = i+1 ; j <= 100; j++)
                for(int k = j+1 ; k <= 100; k++){
                    if(l*l*l<i*i*i+j*j*j+k*k*k)break;
                    else if(l*l*l==i*i*i+j*j*j+k*k*k) cout << "Cube = "<<l<<", Triple = ("<<i<<','<<j<<','<<k<<")\n";
                }                    
    
}