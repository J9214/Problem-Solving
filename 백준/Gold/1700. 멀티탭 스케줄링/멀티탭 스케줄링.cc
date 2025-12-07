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
    
    int n,k,c=0,res=0; cin >> n >> k;
    vi vec(k); // 숫자들
    vvi nums(k+1); // 숫자 별 인덱스들
    vi idx(k+1,0); // 숫자 별 인덱스 순서 관리
    vi visit(k+1); // 현재 꽂아놨는지
    priority_queue<pi> tap;

    for(int i = 0 ; i < k ; i++){
        int d; cin >> d;
        vec[i] = d;
        nums[d].push_back(i);
    }

    for(int i=0 ; i < k ; i++){
        if(!visit[vec[i]])
            if(c>=n){ // 탭이 꽉
                visit[tap.top().second] = 0;
                tap.pop(); res++;
            }
            else c++;            

        visit[vec[i]] = 1;
        idx[vec[i]]++;
        if(idx[vec[i]]<nums[vec[i]].size()) tap.push({nums[vec[i]][idx[vec[i]]],vec[i]});
        else tap.push({99999999,vec[i]});
    }
    cout << res;
}