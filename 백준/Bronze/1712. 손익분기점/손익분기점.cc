#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    long long a, b, c;
    cin >> a >> b >> c;

    if (c <= b) cout << -1 << '\n';
    else cout << a / (c - b) + 1 << '\n';
}