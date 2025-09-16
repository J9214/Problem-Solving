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

    vi vec(26,0);
    stack<double> st;
    int n; cin >> n;
    string s; cin >> s;
    for(int i = 0 ; i < n ; i++) cin >> vec[i];
    double a,b;
    for(auto i : s){
        if(i == '*') {a=st.top(),st.pop(); b=st.top(),st.pop(); st.push(a*b);}
        else if(i == '+') {a=st.top(),st.pop(); b=st.top(),st.pop(); st.push(a+b);}
        else if(i == '/') {a=st.top(),st.pop(); b=st.top(),st.pop(); st.push(b/a);}
        else if(i == '-') {a=st.top(),st.pop(); b=st.top(),st.pop(); st.push(b-a);}
        else st.push(vec[i-'A']);
    }
    cout << fixed; 
    cout.precision(2);
    cout << st.top();
}