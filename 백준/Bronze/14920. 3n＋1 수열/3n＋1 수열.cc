#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    FASTIO
    
    int n; cin >> n;
    int i =1;
    for(; n != 1; i++)
        n = (n%2 ? 3*n+1 : n/2);
    cout << i;
}