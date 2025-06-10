#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    FASTIO

    int a,b,c; cin >> a >> b >> c;
    cout << min(a, b/2+c);
}