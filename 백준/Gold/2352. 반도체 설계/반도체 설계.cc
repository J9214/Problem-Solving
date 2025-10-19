#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<int> vi;

int main(){
    FASTIO
    
    int n; cin >> n;
    vi vec;

    while(n--){
        int d; cin >> d;
        auto it = lower_bound(vec.begin(),vec.end(),d);
        if(it == vec.end()) vec.push_back(d);
        else *it = d;
    }

    cout << vec.size();
}