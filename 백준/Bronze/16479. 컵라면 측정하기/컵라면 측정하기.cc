#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    FASTIO
 
    double a,b,c;cin >> a >> b >> c;
    cout << a*a - (abs(b-c)/2)*(abs(b-c)/2);
}