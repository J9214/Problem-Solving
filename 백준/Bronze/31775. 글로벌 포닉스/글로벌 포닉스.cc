#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    FASTIO

    string a,b,c; cin >> a >> b >> c;
    vector<int> vec(150,0);
    vec[a[0]]++;
    vec[b[0]]++;
    vec[c[0]]++;

    if(vec['l']&&vec['k']&&vec['p']) cout << "GLOBAL";
    else cout << "PONIX";

}