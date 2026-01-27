#include <iostream>

using namespace std;

unsigned long long int factorial(int n){
    if(n <= 1) return 1;
    else return factorial(n - 1) * n;
}
unsigned long long int factorial(int r, int n, int m){
    if(n <= m) return 1;
    else return factorial(r, n - 1, m) * n;
}

unsigned long long int combination(int r, int n){
    int m;

    if(r > n - r) m = r;
    else m = n - r;

    return factorial(r, n, m) / factorial(n - m);
}

int main() {
    unsigned long long int n, r, tc;

    cin >> tc;

    while(tc--){
        cin >> r >> n;

        cout << combination(r, n) << '\n';
    }

    return 0;
}
