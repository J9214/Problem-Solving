#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


int main(){
    FASTIO
    
    double res = -1.5;
    int a,b,c,d,e,f; 
    cin >> a >> b >> c >> d >> e >> f;
    res += a*13+b*7+c*5+d*3+e*3+f*2;
    cin >> a >> b >> c >> d >> e >> f;
    res -= a*13+b*7+c*5+d*3+e*3+f*2;
    if(res>0) cout << "cocjr0208";
    else cout << "ekwoo";
}