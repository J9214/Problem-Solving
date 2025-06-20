#include<bits/stdc++.h>
using namespace std;
int main(){
    string s; cin >> s;
    vector<int> vec(150,0);
    for(auto i : s){
        vec[i]++;
    }
    if(vec['M']&&vec['O']&&vec['B']&&vec['I']&&vec['S']) cout << "YES";
    else cout << "NO";
}