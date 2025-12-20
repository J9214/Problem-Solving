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

struct Ant{
    Ant():k(""), vec({}){};
    Ant(string k, vector<Ant> vec):k(k), vec(vec){};

    string k;
    vector<Ant> vec;
};

void Result(Ant& ant, int d){
    sort(ant.vec.begin(),ant.vec.end(),[](Ant &a, Ant &b){
        return a.k < b.k;
    });

    for(auto i: ant.vec){
        for(int i = 0 ; i < d; i++) cout << "--";
        cout << i.k << '\n';
        Result(i, d+1);
    }
}
int main(){
    FASTIO
    
    Ant root;

    int n; cin >> n;
    while(n--){
        int m; cin >> m;
        Ant* curr = &root;

        for(int i = 0 ; i < m ; i ++){
            string s; cin >> s;
            auto it = find_if(curr->vec.begin(), curr->vec.end(), [&](const Ant &a){return a.k == s;});

            if(it == curr->vec.end()){
                curr->vec.emplace_back(s,vector<Ant>{});
                curr = &curr->vec.back();
            }
            else{
                curr = &*it;
            }
        }
    }

    Result(root,0);
}