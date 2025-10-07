#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    FASTIO
    int n,a=0; cin >> n;
    string s; cin >> s;
    for(auto i:s) a+=i%2?1:-1;
    cout << (a>0?1:a<0?0:-1);
}