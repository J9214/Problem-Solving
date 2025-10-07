#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    FASTIO
    int n,a=0; cin >> n;
    char c[n];
    cin >> c;
    for(auto i:c) a+=i%2?1:-1;
    cout << (a>0?1:a<0?0:-1);
}