#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<ll> vll;

int main(){
    FASTIO

    ll n, t=1; cin >> n;
    if(n==0) {cout << "NO"; return 0;}
    vll vec;
    vec.push_back(1);
    for(int i = 1; t < 1000000000000000000; i++, t*=i)
        vec.push_back(t);

    for(int i = vec.size()-1 ; i>=0; i--)
        n-= (n>=vec[i]) * vec[i];
    
    cout << (n?"NO":"YES");
}