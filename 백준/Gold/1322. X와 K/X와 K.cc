#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    FASTIO
 
    long long n, m, i; cin >> n >> m;
    long long b = n;

    for(i = 0 ; m && i < 64 ; i++){
        if(n&1LL<<i) continue;
        b |= (m&1)<<i;
        m>>=1;
    }

    cout << b-n;
}