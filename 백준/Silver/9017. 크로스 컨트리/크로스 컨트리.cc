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
        int n; cin >> n;
        map<int,int> mp;
        vi vec1(n);
        vector<pair<int, vi>> vec(201);
        for(int i = 0; i < vec.size(); i++) vec[i].first = i;
        for(int i = 0 ; i < n; i++) {
            cin >> vec1[i];
            mp[vec1[i]]++;
        }
        for(int i = 0 ; i < vec1.size(); i++) {
            if(mp[vec1[i]]<6) vec1.erase(vec1.begin()+i,vec1.begin()+i+1), i--;
        }

        for(int i = 0 ; i < vec1.size(); i++) {
            vec[vec1[i]].second.push_back(i);
        }

        sort(vec.begin(),vec.end(),[](pair<int, vi> &a, pair<int, vi> &b){
            return a.second.size() > b.second.size();
        });
        while(vec.back().second.size()<6) vec.pop_back();
        for(auto &v : vec)
            for(int i=1; i < 4; i++)
                v.second[i] += v.second[i-1];
        sort(vec.begin(),vec.end(),[](pair<int, vi> &a, pair<int, vi> &b){
            if(a.second[3] == b.second[3]) {
                return a.second[4] < b.second[4];
            }
            return a.second[3] < b.second[3];
        });
        
        cout << vec[0].first << '\n';
    }
}