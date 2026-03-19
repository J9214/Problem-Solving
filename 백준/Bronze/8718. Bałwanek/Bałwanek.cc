#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long x, k;
    cin >> x >> k;

    x *= 1000;
    k *= 1000;

    if (7 * k <= x) {
        cout << 7 * k << '\n';
    }
    else if (7 * k <= 2 * x) {
        cout << 7 * k / 2 << '\n';
    }
    else if (7 * k <= 4 * x) {
        cout << 7 * k / 4 << '\n';
    }
    else {
        cout << 0 << '\n';
    }
}