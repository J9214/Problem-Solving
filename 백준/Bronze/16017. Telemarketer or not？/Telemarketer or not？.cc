#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    FASTIO

    int a,b,c,d; cin >> a >> b >> c >> d;
    if(a>=8&&d>=8&&c==b) cout << "ignore";
    else cout << "answer";
}