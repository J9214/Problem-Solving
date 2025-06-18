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

int cnt = 0, stage=0;
vi robot(200,0), belt(200,0);
int u, d, n, k;
void first(){
    u = (u-1+n*2) % (n*2);
    d = (u+n-1) % (n*2);
    if(robot[d]) robot[d]=0;
}

void second(){
    for(int i = (d-1+n*2)%(n*2) ; i != u; i = (i-1+n*2)%(n*2)){
        int next=(i+1)%(n*2);
        if(belt[next] && robot[i] && !robot[next]) {
            swap(robot[i],robot[next]);
            belt[next]--;
            if(belt[next]==0) cnt++;
        }
    }
    if(robot[d]) robot[d]=0;
}

void third(){
    if(!robot[u] && belt[u]>0){
        robot[u] = 1;
        belt[u]--;
        if(belt[u]==0) cnt++;
    }
}

int main(){
    FASTIO

    cin >> n >> k;
    for(int i = 0;  i< n*2 ; i++)cin >> belt[i];
    u=0,d=n-1;
    while(k>cnt){
        stage++;
        first(); // 벨트 회전
        second(); // 로봇 한칸 전진
        third(); // 로봇 올리기
    }

    cout << stage;
}