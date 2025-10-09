#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    cin.ignore();
    while(n--){
        string s; getline(cin, s);
        if(s.back()!='.')s+='.';
        cout << s << '\n';
    }
}