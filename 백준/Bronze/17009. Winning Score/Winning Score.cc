#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> vec(2,0);
    
    for(int i = 0 ; i < 2; i ++){
        for(int j = 3; j >= 1; j--){
            int a; cin >> a;
            vec[i]+=a*j;
        }
    }
    cout << ((vec[0]>vec[1])?"A":(vec[0]<vec[1])?"B":"T");
} 