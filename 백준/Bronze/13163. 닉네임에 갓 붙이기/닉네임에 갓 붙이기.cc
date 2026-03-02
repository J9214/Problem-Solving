#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    FASTIO
 
    int n; cin >> n;
    cin.ignore();
    while(n--){
        string s; getline(cin, s);
        cout << "god";
        for(int i = s.find(' ',0)+1; i < s.size(); i++)
            if(s[i]!=' ') cout << s[i];
        cout << '\n';
    }
}