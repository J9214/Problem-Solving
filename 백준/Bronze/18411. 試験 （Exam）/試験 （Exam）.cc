#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    FASTIO

    vector<int> vec(3);
    for(int i = 0; i<3;i++) cin >> vec[i];
    sort(vec.begin(), vec.begin()+3);
    cout << vec[1]+vec[2];
}