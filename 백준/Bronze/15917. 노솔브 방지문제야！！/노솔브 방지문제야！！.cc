#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    
    while(t--){
        int d; cin >> d;
        bitset<32> b(d);
        
        cout << (b.count()==1?1:0) << '\n';
    }
}