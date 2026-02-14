#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    FASTIO
 
    int n, m, i=0; cin >> n >> m;

    bitset<64> b(n);

    for(int i = 0 ; m && i < 64 ; i++){
        if(b[i]) continue;
        b[i] = m&1;
        m>>=1;
    }

    cout << b.to_ullong()-n;
}