#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    FASTIO

    int n; cin >> n;
    cout << (n%7==0||n%7==2?"CY":"SK");
}