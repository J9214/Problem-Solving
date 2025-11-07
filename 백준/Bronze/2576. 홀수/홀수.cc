#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FASTIO

    int n, s=0, m=1000;
    vector<int> vec(7);
    for(int i = 0 ; i < 7 ; i++)
        cin >> vec[i];
    for(int i = 0 ; i < 7 ; i++){
        if(vec[i]%2==1){
            s+=vec[i];
            m=min(m,vec[i]);
        } 
    }
    if(m>100) cout << -1;
    else {
        cout << s << '\n' << m;
    }
    return 0;
}
