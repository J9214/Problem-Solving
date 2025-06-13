#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    FASTIO

    int a;cin >> a;
    int res =0;
    for(int i= 0; i < 5; i++){
        int b; cin>>b;
        if(b==a) res++;
    }
    cout <<res;
}