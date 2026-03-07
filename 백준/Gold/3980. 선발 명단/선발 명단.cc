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

    vi check(11,0);
    vector<vector<pi>> vec(11); 
    int m;
    void func(int s,int num){ 
        if(num==11){
            m=max(m,s);
            return;
        }

        for(int i = 0 ; i < vec[num].size() ; i++){
            if(check[vec[num][i].first]) continue;
            check[vec[num][i].first]=1;
            func(s+vec[num][i].second,num+1);
            check[vec[num][i].first]=0;
        }
    }
    int main(){
        FASTIO
    
        int t; cin >> t;
        while(t--){
            check.assign(11,0);
            vec.clear();
            vec.resize(11);
            m=0;
            for(int i = 0 ; i < 11; i++)for(int j = 0 ; j < 11; j++){
                int d; cin >> d;
                if(d) vec[j].push_back({i,d});
            }
            func(0,0);
            cout << m <<'\n';
        }
    }