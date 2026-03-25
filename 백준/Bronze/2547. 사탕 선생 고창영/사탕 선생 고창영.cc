#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;

int main(){
    FASTIO
 
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll r = 0;
        for(int i = 0 ; i < n ; i++){
            ll d; cin >> d;
            r += d;
            r %= n;
        }
        if(r)cout << "NO";
        else cout <<"YES";
        cout << '\n';
    }
}