#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    FASTIO

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int p1=0,p2=0;
        while(n--){
            char c1,c2; cin >> c1 >> c2;
            if(c1=='R'){
                if(c2=='S') p1++;
                if(c2=='P') p2++;
            }
            else if(c1=='S'){
                if(c2=='R') p2++;
                if(c2=='P') p1++;
            }
            else if(c1=='P'){
                if(c2=='R') p1++;
                if(c2=='S') p2++;
            }
        }
        cout << (p1==p2 ? "TIE" : p1>p2?"Player 1" : "Player 2"); 
        cout << '\n';
    }
}