#include <iostream>

using namespace std;

int cycle(int a, int b, int t){
    a = (a % 10) * 10 + (a % 10 + a / 10) % 10;
    b++;
    
    if(a == t) return b;
    else return cycle(a, b, t); 
}

int main(){
    int a, b = 0;
    cin >> a;

    cout << cycle(a, b, a);

    return 0; 
}