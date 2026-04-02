#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,p,q; 
map<ll,ll> mp;
ll func(ll n){
    if(mp[n]) return mp[n];
    return mp[n] = func(n/p)+func(n/q);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    mp[0]=1;
    cin >> n >> p >> q;
    cout << func(n);
}