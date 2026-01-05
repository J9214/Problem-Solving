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

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);

    int a=10000,b=10000;
    vi vec(10000);
    iota(vec.begin(), vec.end(), 1);
    shuffle(vec.begin(),vec.end(),generator);
        
    for(int i = 0,c ; i < 10000; i ++){
        cout << "? A " << vec[i] << endl;
        cin >> c;
        
        if(c){
            a=vec[i];
            break;
        }
    }
    
    shuffle(vec.begin(),vec.end(),generator);
    for(int i = 0,c ; i < 10000; i ++){
        cout << "? B " << vec[i] << endl;
        cin >> c;
        
        if(c){
            b=vec[i];
            break;
        }
    }

    cout << "! " << a+b;
}