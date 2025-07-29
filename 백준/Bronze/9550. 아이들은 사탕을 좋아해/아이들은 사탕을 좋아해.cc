#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin >> t;
    while(t--){
        int a,b,res=0;cin >> a >> b;
        while(a--){
            int c; cin >> c;
            res+=c/b;
        }
        cout << res << '\n';
    }
}