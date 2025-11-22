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

    int t; cin >> t;
    while(t--){
        priority_queue<int> pq1;
        priority_queue<int,vi, greater<int>> pq2;
        map<int,int> mp;
        int n ; cin >> n;
        while(n--){
            char c; cin >> c;
            int d; cin >> d;
            if(c=='I'){
                pq1.push(d);
                pq2.push(d);
                mp[d]++;
            }
            else {
                if((d==1 && pq1.size())) mp[pq1.top()]--, pq1.pop();
                if((d==-1 && pq2.size())) mp[pq2.top()]--, pq2.pop();
                while(pq1.size() && !mp[pq1.top()]) pq1.pop();
                while(pq2.size() && !mp[pq2.top()]) pq2.pop();
                if(pq1.empty() || pq2.empty() || pq1.top()<pq2.top()) {
                    while(pq1.size()) pq1.pop(); 
                    while(pq2.size()) pq2.pop();
                }
            }
        }
        if(pq1.empty()) cout << "EMPTY";
        else cout << pq1.top() <<  ' ' << pq2.top();
        cout << '\n';
    }
}