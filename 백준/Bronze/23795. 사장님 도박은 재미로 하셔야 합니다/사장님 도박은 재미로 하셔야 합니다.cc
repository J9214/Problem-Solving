#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    FASTIO

    int a,res=0;
    while(cin >> a){
        if(a==-1) break;
        res+=a;
    }
    cout <<res;
}