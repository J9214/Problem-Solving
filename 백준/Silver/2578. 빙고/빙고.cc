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
vvi mat(5,vi(5));
int bingo(){
    int n = 0;
    for(int i = 0 ; i < 5; i++){
        int t = 0;
        for(int j = 0 ; j < 5; j++)
            if(!mat[i][j]) t++;
        if(t==5) n++;
    }

    for(int i = 0 ; i < 5; i++){
        int t = 0;
        for(int j = 0 ; j < 5; j++)
            if(!mat[j][i]) t++;
        if(t==5) n++;
    }

    if(!mat[0][0]&&!mat[1][1]&&!mat[2][2]&&!mat[3][3]&&!mat[4][4]) n++;
    if(!mat[0][4]&&!mat[1][3]&&!mat[2][2]&&!mat[3][1]&&!mat[4][0]) n++;

    return (n>=3 ? 1 : 0);
}
int main(){
    FASTIO

    for(int i = 0 ; i < 5; i++)
        for(int j = 0 ; j <5; j++)
            cin >> mat[i][j];

    for(int i = 1 ; i <= 25; i++){
        int d; cin >> d;
        for(int j = 0 ; j < 5 ; j++){
            for(int k = 0 ; k < 5; k++){
                if(mat[j][k] == d) mat[j][k] = 0;
            }
        }
        if(bingo()){
            cout << i;
            return 0;
        }
    }
}