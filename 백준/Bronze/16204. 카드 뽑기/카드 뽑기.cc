#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    FASTIO

    int n,m,k; cin >> n >> m >> k;
    cout << min(m,k) + min(n-m,n-k);
}